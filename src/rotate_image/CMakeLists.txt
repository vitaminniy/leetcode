project(rotate_image)

add_executable(${PROJECT_NAME} rotate.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
