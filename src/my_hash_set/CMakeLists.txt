project(my_hash_set LANGUAGES CXX)
add_library(${PROJECT_NAME})

file(GLOB SOURCES *.cpp)
foreach(subdir
		src)

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

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(ut)
