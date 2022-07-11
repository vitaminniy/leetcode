project(199_bt_right_side_view LANGUAGES CXX)

add_library(${PROJECT_NAME})

file(GLOB SOURCES *.cpp)
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME}
    PUBLIC
        -Wall
        -Werror
        -Wextra
        -Wpedantic
        -Wreturn-type
)
