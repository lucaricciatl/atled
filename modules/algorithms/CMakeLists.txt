# Create a library from the submodule's source files
add_library(algorithms
    ./src/algorithms.cpp
)


# Specify include directories for the submodule
target_include_directories(algorithms PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(algorithms PROPERTIES FOLDER "modules")
