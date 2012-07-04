project(IBDE CXX)
cmake_minimum_required(VERSION 2.8)

# Set g++ compiler flags if GNU C++ compiler is being used
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 --param max-gcse-memory=1000000000 --param gcse-unrestricted-cost=0 --param max-hoist-depth=0")
endif()

find_package(Qt4 REQUIRED QtCore QtGui)
include(${QT_USE_FILE})
include_directories(${QT_INCLUDE_DIR})

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

include_directories(${IBDE_SOURCE_DIR}/inc)
add_subdirectory(${IBDE_SOURCE_DIR}/src)
