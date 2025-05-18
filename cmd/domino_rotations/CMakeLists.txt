project(domino_rotations LANGUAGES CXX)

set(
  SOURCES

  main.cpp
  rotate.cpp
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
