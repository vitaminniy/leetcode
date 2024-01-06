cmake_minimum_required(VERSION 3.22)

project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(ClangFormat)

find_package(GTest)
if (GTest_FOUND)
	message(STATUS "Found GTest")
	message(STATUS "GTest Include dir(s): ${GTEST_INCLUDE_DIRS}")
	message(STATUS "GTest Libraries: ${GTEST_LIBRARIES}")
	message(STATUS "GTest Main Libraries: ${GTEST_MAIN_LIBRARIES}")
	message(STATUS "GTest Root: ${GTEST_ROOT}")
else()
	include(FetchContent REQUIRED)
	FetchContent_Declare(
		googletest
		# Specify the commit you depend on and update it regularly.
		URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
	)
	# For Windows: Prevent overriding the parent project's compiler/linker
	# settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)
endif()

add_subdirectory(src)

enable_testing()
