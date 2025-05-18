set(
  SOURCES

  solution.cpp
  solution_test.cpp
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

include(GoogleTest)
target_link_libraries(${PROJECT_NAME} PRIVATE
  GTest::gtest
  GTest::gtest_main
)

enable_testing()
gtest_discover_tests(${PROJECT_NAME})
