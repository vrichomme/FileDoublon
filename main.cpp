#include "filesystemwalker.h"

#include "cstdtchar"

#include "winnetwk.h"
#pragma comment(lib, "Mpr.lib")

#if 0



std::tstring ConvertToUNC(std::tstring sPath)
{
   TCHAR temp;
   UNIVERSAL_NAME_INFO * puni = NULL;
   DWORD bufsize = 0;
   std::tstring sRet = sPath;
   //Call WNetGetUniversalName using UNIVERSAL_NAME_INFO_LEVEL option
   if (WNetGetUniversalName(sPath.c_str(),
      UNIVERSAL_NAME_INFO_LEVEL,
      (LPVOID)&temp,
      &bufsize) == ERROR_MORE_DATA)
   {
      // now we have the size required to hold the UNC path
      WCHAR * buf = new WCHAR[bufsize + 1];
      puni = (UNIVERSAL_NAME_INFO *)buf;
      if (WNetGetUniversalName(sPath.c_str(),
         UNIVERSAL_NAME_INFO_LEVEL,
         (LPVOID)puni,
         &bufsize) == NO_ERROR)
      {
         sRet = std::tstring(puni->lpUniversalName);
      }
      delete[] buf;
   }

   return sRet;;
}

int _tmain(int argc, TCHAR * argv[])
{
   DWORD dwRetVal;
   WCHAR Buffer[1024];
   DWORD dwBufferLength = 1024;

   //std::tstring sTmp = ConvertToUNC(_T("C:"));



   UNIVERSAL_NAME_INFO * unameinfo;
   REMOTE_NAME_INFO *remotenameinfo;

   wprintf(L"Calling WNetGetUniversalName with Local Path = %s\n", argv[1]);

   unameinfo = (UNIVERSAL_NAME_INFO *)&Buffer;
   dwRetVal = WNetGetUniversalName(argv[1], UNIVERSAL_NAME_INFO_LEVEL, (LPVOID)unameinfo, &dwBufferLength);
   //
   // If the call succeeds, print the user information.
   //
   if (dwRetVal == NO_ERROR) {

      wprintf(L"WNetGetUniversalName returned success for InfoLevel=UNIVERSAL_NAME_INFO_LEVEL\n");
      wprintf(L"\tUniversal name = %s\n", unameinfo->lpUniversalName);
   }

   else {
      wprintf(L"WNetGetUser failed for InfoLevel=UNIVERSAL_NAME_INFO_LEVEL with error: %u\n", dwRetVal);
   }


   remotenameinfo = (REMOTE_NAME_INFO *)&Buffer;
   dwRetVal = WNetGetUniversalName(argv[1], REMOTE_NAME_INFO_LEVEL,
      (LPVOID)remotenameinfo, &dwBufferLength);
   //
   // If the call succeeds, print the user information.
   //
   if (dwRetVal == NO_ERROR) {

      wprintf(L"WNetGetUniversalName returned success for InfoLevel=REMOTE_NAME_INFO_LEVEL\n");
      wprintf(L"\tUniversal name = %s\n", remotenameinfo->lpUniversalName);
      wprintf(L"\tConnection name = %s\n", remotenameinfo->lpConnectionName);
      wprintf(L"\tRemaining path = %s\n", remotenameinfo->lpRemainingPath);
   }

   else {
      wprintf(L"WNetGetUser failed for InfoLevel=REMOTE_NAME_INFO_LEVEL with error: %u\n", dwRetVal);
   }
}
#else

int _tmain(int argc, TCHAR *argv[])
{
    FileSystemWalker walker;

    DWORD dwErr = 0;
    TCHAR szBuffer[1024];
    DWORD dwLen = _countof(szBuffer);

    dwErr = GetLongPathName(_T("C:\\Users\\Vincent\\AppData\\Roaming\\Apple Computer\\MobileSync"),szBuffer, dwLen);
    dwErr = WNetGetConnection(_T("C:"), szBuffer, &dwLen);

    walker.addExtension(_T(".png"));
    walker.addExtension(_T(".jpg"));
    walker.addExtension(_T(".jpeg"));
    //walker.addPath(_T("C:\\Users\\Vincent\\Pictures"));
    walker.addPath(_T("C:\\Users\\Vincent\\AppData\\Roaming\\Apple Computer\\MobileSync"));
    //walker.addPath(_T("E:\\Backup\\PointedFromSymlink"));
 
    walker.startWalking();

    return 0;
}
#endif