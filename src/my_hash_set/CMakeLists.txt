project(my_hash_set LANGUAGES CXX)
add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
target_compile_options(${PROJECT_NAME}
	INTERFACE
		-Wall
		-Werror
		-Wextra
		-Wpedantic
		-Wreturn-type
)

target_include_directories(${PROJECT_NAME}
	INTERFACE
		${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(ut)
