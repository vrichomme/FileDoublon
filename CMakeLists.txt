cmake_minimum_required(VERSION 3.13.0)
project(FileDoublon)
 
#Bring the headers, such as Student.h into the project
include_directories(${CMAKE_SOURCE_DIR})
 
#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h" "*.hpp")

if(WIN32)

# By default only WIN32 is defined but boost detects windows api with _WIN32
ADD_DEFINITIONS(-D_WIN32 )
ADD_DEFINITIONS(-DUNICODE -D_UNICODE )

set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT ${CMAKE_SOURCE_DIR}/stage/boost_1_71_0)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_DEBUG ON)

# disable autolinking in boost
# add_definitions( -DBOOST_ALL_NO_LIB )
# add_definitions( -DBOOST_ALL_DYN_LINK )
  
endif(WIN32)

find_package(Boost 1.71.0 COMPONENTS filesystem)
if(Boost_FOUND)

	include_directories(${CMAKE_SOURCE_DIR}/stdtchar/include)
	include_directories(${Boost_INCLUDE_DIRS}) 
	LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
	
	add_executable(FileDoublon 
		${HEADERS}
		${SOURCES}
	)
	 target_link_libraries(FileDoublon 
		 ${Boost_LIBRARIES}
	 )

else(!Boost_FOUND)
    message(STATUS "Cannot find boost!")
endif(Boost_FOUND)


