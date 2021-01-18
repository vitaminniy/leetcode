cmake_minimum_required(VERSION 3.19)

project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CTEST_ARGUMENTS "--output-on-failure")

add_compile_options(-Wall -Werror -Wextra -Wpedantic)
enable_testing()

add_subdirectory(swap_nodes_in_pairs)
