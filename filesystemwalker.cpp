#include "filesystemwalker.h"
#include "filenamepolicy.h"

#include <boost/algorithm/string.hpp>
#include <boost/locale.hpp>
#include <algorithm>

fs::path resolve(
   const fs::path& p,
   const fs::path& base = fs::current_path()
)
{
   fs::path abs_p = fs::absolute(p);
   fs::path result;
   for (fs::path::iterator it = abs_p.begin();
      it != abs_p.end();
      ++it)
   {
      if (*it == _T(".."))
      {
         // /a/b/.. is not necessarily /a if b is a symbolic link
         if (fs::is_symlink(result))
            result /= *it;
         // /a/b/../.. is not /a/b/.. under most circumstances
         // We can end up with ..s in our result because of symbolic links
         else if (result.filename() == _T(".."))
            result /= *it;
         // Otherwise it should be safe to resolve the parent
         else
            result = result.parent_path();
      }
      else if (*it == _T("."))
      {
         // Ignore
      }
      else
      {
         // Just cat other path entries
         result /= *it;
      }
   }
   //std::replace(result.begin(), result.end(), L'/', L'\\');

   return result;
}

FileSystemWalker::FileSystemWalker()
{

}

void FileSystemWalker::addExtension(const std::tstring & sExt)
{
   m_exts.emplace_back(sExt);
}

void FileSystemWalker::addPath(const std::tstring & sPath)
{
   // Why does boost canonical and / operator is adding a / ater colon drive !!!!
  // I have to call make_preferred()
#ifdef WIN32
   const std::tstring longPathPrefix = _T("\\\\?\\");
   fs::path p = fs::canonical(/*longPathPrefix + */sPath).make_preferred();
#else
   fs::path p = fs::canonical(sPath);
#endif
   m_paths.emplace_back(p);
}

bool FileSystemWalker::isCandidateBasedOnName(const fs::path& path)
{
   return false;
}



void FileSystemWalker::startWalking_(TraversalContext& ctx)
{
   // Note: recursive_directory_iterator is broken on Windows with junction
   for (const auto& entry : fs::directory_iterator(ctx.curPathParentDir))
   {
      ctx.curPathEntry = entry.path();
      ctx.curStatusEntry = fs::status(ctx.curPathEntry);
      ctx.curSymlinkStatusEntry = fs::symlink_status(ctx.curPathEntry);

      if (fs::is_directory(ctx.curStatusEntry))
      {
         ctx.curPathParentDir = entry.path();
         ctx.level += 1;
         startWalking_(ctx);
      }
      else if(fs::is_regular_file(ctx.curStatusEntry))
      {
         const auto& ext = boost::algorithm::to_lower_copy(ctx.curPathEntry.extension().native());
         if (std::find(m_exts.begin(), m_exts.end(), ext) != m_exts.end())
         {
            bool bIsCandidate = isCandidateBasedOnName(ctx.curPathEntry);

            uintmax_t size = fs::file_size(ctx.curPathEntry);
            auto itFound = m_fileIndexes.find(size);
            if (itFound == m_fileIndexes.end())
            {
               m_fileIndexes[size] = entry.path();
            }
            else
            {
               const fs::path& orgFileEntry = (*itFound).second;
               if (filenameIsContained(ctx.curPathEntry.stem().native(), orgFileEntry.stem().native()))
               {
                  m_doublons.emplace_back(FsItem(ctx.curPathEntry, orgFileEntry));
               }
            }
         }
      }
   }
}

void FileSystemWalker::startWalking()
{
   for (auto& path : m_paths)
   {
      TraversalContext ctx;
      ctx.curPathParentDir = path;
      startWalking_(ctx);
   }
}


