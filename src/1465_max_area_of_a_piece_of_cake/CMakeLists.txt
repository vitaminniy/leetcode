project(1465_max_area_of_a_piece_of_cake LANGUAGES CXX)

add_executable(${PROJECT_NAME})

file(GLOB SOURCES *.cpp)
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
        GTest::gtest
        GTest::gtest_main
)

enable_testing()
gtest_discover_tests(${PROJECT_NAME})
