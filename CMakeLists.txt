# CMake Lists 

cmake_minimum_required (VERSION 3.31.6)
 
set(PROJECT_NAME_STR OgreSceneLoader)
project(${PROJECT_NAME_STR} C CXX)

#----------------------------
# Additional CMake Packages
#----------------------------
include(CMakePrintHelpers)
include(FetchContent)

#----------------------------
# Configure build type
#----------------------------

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

#----------------------------
# Directories
#----------------------------

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/assets)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#----------------------------------------------
# Configure RPATH for systems that support it
#-----------------------------------------------
if(NOT WIN32)
    # Output has correct LD_LIBRARY_PATH
    # Note: set this before you make add the exe!
    set(CMAKE_INSTALL_RPATH . CACHE STRING "" FORCE)#"${CMAKE_INSTALL_BINDIR}")

    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE CACHE BOOL "" FORCE)
endif()


#-----------------------------
# Compiler settings
#-----------------------------

# Set C++ standard (we're going with 2020). 
set(CMAKE_CXX_STANDARD 20)

if(CMAKE_COMPILER_IS_GNUCXX)
  # New CMakeOnly
  # add_definitions(-Wall -ansi -Wno-deprecated -pthread)
  # Note: -ansi reinforces C90, will override c++11
  set(GNU_EXTRA_STUFF "-Wall -Wno-deprecated -Wno-multichar -pthread" CACHE STRING "" FORCE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GNU_EXTRA_STUFF}" CACHE STRING "" FORCE)

endif()

#-------------------
# Configure Threads 
#-------------------
find_package(Threads REQUIRED)

# Recurse into the "maths" etc subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.

# replace with a fast off the shelf maths lib
add_subdirectory (src/maths)

# basic cross platform logging
add_subdirectory (src/strings)

# the DOM
add_subdirectory(src/scene)

# loading files etc. 
add_subdirectory (src/loader)

# user interface test
add_subdirectory(src/gtest)

# user interface
add_subdirectory (src/ui) 

message(STATUS "Cmake is Done!")
