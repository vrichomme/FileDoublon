rem Visual Studio 2012 -> set msvcver=msvc-11.0
rem Visual Studio 2013 -> set msvcver=msvc-12.0
rem Visual Studio 2015 -> set msvcver=msvc-14.0
rem Visual Studio 2017 -> set msvcver=msvc-14.1
rem Visual Studio 2019 -> set msvcver=msvc-14.2

b2 toolset=msvc-14.2 architecture=x86 address-model=64 link=static threading=multi --with-filesystem --with-system --with-locale --variant=release

