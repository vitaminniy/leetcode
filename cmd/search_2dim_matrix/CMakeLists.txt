project(search_2dim_matrix LANGUAGES CXX)

set(
  SOURCES

  main.cpp
  solution.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -Wimplicit-fallthrough
)

enable_testing()
add_test(${PROJECT_NAME} ${PROJECT_NAME})
