project(clone_graph LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC clone.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -Wimplicit-fallthrough
)
