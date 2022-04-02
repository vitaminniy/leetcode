project(swap_nodes_in_pairs)

add_library(${PROJECT_NAME} SHARED solution.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
