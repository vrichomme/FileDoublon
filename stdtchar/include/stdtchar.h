//===- llvm/Support/type_traits.h - Simplfied type traits -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides a template class that determines if a type is a class or
// not. The basic mechanism, based on using the pointer to member function of
// a zero argument to a function was "boosted" from the boost type_traits
// library. See http://www.boost.org/ for all the gory details.
//
//===----------------------------------------------------------------------===//

#ifndef _STDTCHAR_H_
#define _STDTCHAR_H_

#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)

#include <Windows.h>
#include <tchar.h>

typedef TCHAR tchar_t;

#else

#ifdef __cplusplus
extern "C" {
#endif

typedef char tchar_t;

#define _TEOF EOF

#define __T(x) x

#define _tmain main
#define _tWinMain WinMain
#ifdef _POSIX_
#define _tenviron environ
#else
#define _tenviron _environ
#endif
#define __targv __argv

#define _tprintf printf
#define _tprintf_l _printf_l
#define _tprintf_p _printf_p
#define _tprintf_p_l _printf_p_l
#define _tcprintf _cprintf
#define _tcprintf_l _cprintf_l
#define _tcprintf_p _cprintf_p
#define _tcprintf_p_l _cprintf_p_l
#define _vtcprintf _vcprintf
#define _vtcprintf_l _vcprintf_l
#define _vtcprintf_p _vcprintf_p
#define _vtcprintf_p_l _vcprintf_p_l
#define _ftprintf fprintf
#define _ftprintf_l _fprintf_l
#define _ftprintf_p _fprintf_p
#define _ftprintf_p_l _fprintf_p_l
#define _stprintf sprintf
#define _stprintf_l _sprintf_l
#define _stprintf_p _sprintf_p
#define _stprintf_p_l _sprintf_p_l
#define _sctprintf _scprintf
#define _sctprintf_l _scprintf_l
#define _sctprintf_p _scprintf_p
#define _sctprintf_p_l _scprintf_p_l
#define _sntprintf _snprintf
#define _sntprintf_l _snprintf_l
#define _vtprintf vprintf
#define _vtprintf_l _vprintf_l
#define _vtprintf_p _vprintf_p
#define _vtprintf_p_l _vprintf_p_l
#define _vftprintf vfprintf
#define _vftprintf_l _vfprintf_l
#define _vftprintf_p _vfprintf_p
#define _vftprintf_p_l _vfprintf_p_l
#define _vstprintf vsprintf
#define _vstprintf_l _vsprintf_l
#define _vstprintf_p _vsprintf_p
#define _vstprintf_p_l _vsprintf_p_l
#define _vsctprintf _vscprintf
#define _vsctprintf_l _vscprintf_l
#define _vsctprintf_p _vscprintf_p
#define _vsctprintf_p_l _vscprintf_p_l
#define _vsntprintf _vsnprintf
#define _vsntprintf_l _vsnprintf_l

#define _tscanf scanf
#define _tscanf_l _scanf_l
#define _tcscanf _cscanf
#define _tcscanf_l _cscanf_l
#define _ftscanf fscanf
#define _ftscanf_l _fscanf_l
#define _stscanf sscanf
#define _stscanf_l _sscanf_l
#define _sntscanf _snscanf
#define _sntscanf_l _snscanf_l

#define _fgettc fgetc
#define _fgettc_nolock _fgetc_nolock
#define _fgettchar _fgetchar
#define _fgetts fgets
#define _fputtc fputc
#define _fputtc_nolock _fputc_nolock
#define _fputtchar _fputchar
#define _fputts fputs
#define _cputts _cputs
#define _gettc getc
#define _gettc_nolock _getc_nolock
#define _gettch _getch
#define _gettch_nolock _getch_nolock
#define _gettche _getche
#define _gettche_nolock _getche_nolock
#define _gettchar getchar
#define _gettchar_nolock _getchar_nolock
#define _getts gets
#define _cgetts _cgets
#define _puttc putc
#define _puttc_nolock _putc_nolock
#define _puttchar putchar
#define _puttchar_nolock _putchar_nolock
#define _puttch _putch
#define _puttch_nolock _putch_nolock
#define _putts puts
#define _ungettc ungetc
#define _ungettc_nolock _ungetc_nolock
#define _ungettch _ungetch
#define _ungettch_nolock _ungetch_nolock

#define _tcstod strtod
#define _tcstol strtol
#define _tcstoul strtoul
#define _tstof atof
#define _tstol atol
#define _tstoi atoi
#define _tstoi64 _atoi64
#define _tcstod_l _strtod_l
#define _tcstol_l _strtol_l
#define _tcstoul_l _strtoul_l
#define _tstof_l _atof_l
#define _tstol_l _atol_l
#define _tstoi_l _atoi_l
#define _tstoi64_l _atoi64_l

#define _itot _itoa
#define _ltot _ltoa
#define _ultot _ultoa
#define _ttoi atoi
#define _ttol atol

#define _ttoi64 _atoi64
#define _tcstoi64 _strtoi64
#define _tcstoi64_l _strtoi64_l
#define _tcstoui64 _strtoui64
#define _tcstoui64_l _strtoui64_l
#define _i64tot _i64toa
#define _ui64tot _ui64toa

#define _tcscat strcat
#define _tcscpy strcpy
#define _tcsdup _strdup
#define _tcslen strlen
#define _tcsnlen strnlen
#define _tcsxfrm strxfrm
#define _tcsxfrm_l _strxfrm_l
#define _tcserror strerror
#define __tcserror _strerror

#define _texecl _execl
#define _texecle _execle
#define _texeclp _execlp
#define _texeclpe _execlpe
#define _texecv _execv
#define _texecve _execve
#define _texecvp _execvp
#define _texecvpe _execvpe

#define _tspawnl _spawnl
#define _tspawnle _spawnle
#define _tspawnlp _spawnlp
#define _tspawnlpe _spawnlpe
#define _tspawnv _spawnv
#define _tspawnve _spawnve
#define _tspawnvp _spawnvp
#define _tspawnvpe _spawnvpe

#define _tsystem system

#define _tasctime asctime
#define _tctime ctime
#define _tctime32 _ctime32
#define _tctime64 _ctime64
#define _tstrdate _strdate
#define _tstrtime _strtime
#define _tutime _utime
#define _tutime32 _utime32
#define _tutime64 _utime64
#define _tcsftime strftime
#define _tcsftime_l _strftime_l

#define _tchdir _chdir
#define _tgetcwd _getcwd
#define _tgetdcwd _getdcwd
#define _tgetdcwd_nolock _getdcwd_nolock
#define _tmkdir _mkdir
#define _trmdir _rmdir

#define _tfullpath _fullpath
#define _tgetenv getenv
#define _tmakepath _makepath
#define _tpgmptr _pgmptr
#define _get_tpgmptr _get_pgmptr
#define _tputenv _putenv
#define _tsearchenv _searchenv
#define _tsplitpath _splitpath

#ifdef _POSIX_
#define _tfdopen fdopen
#else
#define _tfdopen _fdopen
#endif
#define _tfsopen _fsopen
#define _tfopen fopen
#define _tfreopen freopen
#define _tperror perror
#define _tpopen _popen
#define _ttempnam _tempnam
#define _ttmpnam tmpnam

#define _tchmod _chmod
#define _tcreat _creat
#define _tfindfirst _findfirst
#define _tfindfirst32 _findfirst32
#define _tfindfirst64 _findfirst64
#define _tfindfirsti64 _findfirsti64
#define _tfindfirst32i64 _findfirst32i64
#define _tfindfirst64i32 _findfirst64i32
#define _tfindnext _findnext
#define _tfindnext32 _findnext32
#define _tfindnext64 _findnext64
#define _tfindnexti64 _findnexti64
#define _tfindnext32i64 _findnext32i64
#define _tfindnext64i32 _findnext64i32
#define _tmktemp _mktemp

#ifdef _POSIX_
#define _topen open
#define _taccess access
#else
#define _topen _open
#define _taccess _access
#endif

#define _tremove remove
#define _trename rename
#define _tsopen _sopen
#define _tunlink _unlink

#define _tfinddata_t _finddata_t
#define _tfinddata32_t _finddata32_t
#define _tfinddata64_t __finddata64_t
#define _tfinddatai64_t _finddatai64_t
#define _tfinddata32i64_t _finddata32i64_t
#define _tfinddata64i32_t _finddata64i32_t

#define _istascii __isascii
#define _istcntrl iscntrl
#define _istcntrl_l _iscntrl_l
#define _istxdigit isxdigit
#define _istxdigit_l _isxdigit_l

#define _tstat _stat
#define _tstat32 _stat32
#define _tstat32i64 _stat32i64
#define _tstat64 _stat64
#define _tstat64i32 _stat64i32
#define _tstati64 _stati64

#define _tsetlocale setlocale

#ifdef __cplusplus
}
#endif /*__cplusplus*/


#endif

#endif /*_STDTCHAR_H_*/
