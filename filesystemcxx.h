#pragma once

//#define USE_BOOST_FS 1

#if USE_BOOST_FS

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
namespace sys = boost::system;

#else

#include <filesystem>
namespace fs = std::filesystem;
namespace sys = std;

#endif

