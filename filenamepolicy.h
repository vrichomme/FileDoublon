#include "cstdtchar"

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>


template<typename Range1T, typename Range2T>
inline bool filenameIsContained(
   const Range1T& filenameNoExtA,
   const Range2T& filenameNoExtB)
{
   bool bRet = false;

   const std::tstring curFnameNoExt = boost::algorithm::to_lower_copy(filenameNoExtA);
   const std::tstring orgFnameNoExt = boost::algorithm::to_lower_copy(filenameNoExtB);

   std::vector<std::tstring> vecs{ orgFnameNoExt, curFnameNoExt };
   std::sort(vecs.begin(), vecs.end(), [](const std::tstring & a, const std::tstring & b) {
      return a.size() < b.size();
   });

   // Two files have the same size and share same part of name => Hurray it's a doublon
   if (boost::contains(orgFnameNoExt, curFnameNoExt))
   {
      bRet = true;
   }

   return bRet;
}