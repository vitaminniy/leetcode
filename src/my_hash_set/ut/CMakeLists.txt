project(my_hash_set_ut LANGUAGES CXX)
add_executable(${PROJECT_NAME})

file(GLOB SOURCES *.cpp)
foreach(subdir)

	file(GLOB sources ${subdir}/*.cpp)
	list(APPEND SOURCES ${sources})
endforeach()

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}
	PRIVATE
		-Wall
		-Werror
		-Wextra
		-Wpedantic
		-Wreturn-type
)

include(GoogleTest)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		my_hash_set
		GTest::gtest
		GTest::gtest_main
)

enable_testing()
gtest_discover_tests(${PROJECT_NAME})
