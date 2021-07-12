cmake_minimum_required(VERSION 3.20)

project(isomorphic_strings LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CTEST_ARGUMENTS "--output-on-failure")

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src)

enable_testing()
