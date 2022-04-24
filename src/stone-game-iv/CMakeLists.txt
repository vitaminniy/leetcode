project(stone-game-ix LANGUAGES CXX)

enable_testing()

add_executable(${PROJECT_NAME})

file(GLOB SOURCES *.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}
	PRIVATE
		-Wall
		-Werror
		-Wextra
)

include(GoogleTest)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    GTest::gtest
    GTest::gtest_main
)

gtest_discover_tests(${PROJECT_NAME})
