@echo off
rem Directory to boost root
set boost_dir=boost_1_71_0
  
rem Number of cores to use when building boost
set cores=%NUMBER_OF_PROCESSORS%
  
rem What toolset to use when building boost.
  
rem Visual Studio 2012 -> set msvcver=msvc-11.0
rem Visual Studio 2013 -> set msvcver=msvc-12.0
rem Visual Studio 2015 -> set msvcver=msvc-14.0
rem Visual Studio 2017 -> set msvcver=msvc-14.1
  
set msvcver=msvc-14.1
  
rem Start building boost
echo Building %boost_dir% with %cores% cores using toolset %msvcver%.
  
cd %boost_dir%
call bootstrap.bat
  
rem Most libraries can be static libs
b2 --with-system --with-filesystem --with-locale -j%cores% toolset=%msvcver% address-model=64 architecture=x86 link=static threading=multi runtime-link=shared variant=debug stage --stagedir=stage/x64 
rem b2 --with-filesystem -j%cores% toolset=%msvcver% address-model=32 architecture=x86 link=static threading=multi runtime-link=static variant=debug stage --stagedir=stage/win32
b2 --with-system --with-filesystem --with-locale -j%cores% toolset=%msvcver% address-model=64 architecture=x86 link=static threading=multi runtime-link=shared variant=release stage --stagedir=stage/x64 
rem b2 -j%cores% toolset=%msvcver% address-model=32 architecture=x86 link=static threading=multi runtime-link=static variant=release stage --stagedir=stage/win32