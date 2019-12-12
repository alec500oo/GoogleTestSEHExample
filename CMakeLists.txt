# CMakeList.txt : CMake project for GoogleTestSEH, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("GoogleTestSEH")

# Change to 17 fo expose the exception
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)

set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/googletest")
add_subdirectory("${CMAKE_SOURCE_DIR}/src")
