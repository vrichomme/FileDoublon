#ifndef FILESYSTEMWALKER_H
#define FILESYSTEMWALKER_H

#include "cstdtchar"
#include "filesystemcxx.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>


struct FsItem
{
   FsItem() {};

   explicit FsItem(const fs::path& orgFileItempath, const fs::path& curFileItempath)
      : FirstSeenItemPath(orgFileItempath)
      , DuplicatedItemPath(curFileItempath)
   {};

   fs::path FirstSeenItemPath;
   fs::path DuplicatedItemPath;
};

class FileSystemWalker 
{    
   struct TraversalContext
   {
      fs::path curPathParentDir;
      fs::path curPathEntry;
      fs::file_status curStatusEntry;
      fs::file_status curSymlinkStatusEntry;
      int level;
   };
public:
   enum Options
   {
   };
    explicit FileSystemWalker();

    void addExtension(const std::tstring& sExt);

    void addPath(const std::tstring& sPath);

    void startWalking();

   void setWalkingOptions(Options eOptions);
private:
   void startWalking_(TraversalContext& ctx);

   bool isCandidateBasedOnName(const fs::path& path);

private:
    bool m_bIsWalking = false;
    std::vector<fs::path> m_paths;
    std::vector<fs::path> m_exts;
    std::unordered_map<uintmax_t, fs::path> m_fileIndexes;
    std::vector<FsItem> m_doublons;
    std::vector<FsItem> m_candidates;

};

#endif // FILESYSTEMWALKER_H
