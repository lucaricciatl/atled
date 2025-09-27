# Create a library from the submodule's source files
add_library(vision
    ./src/vision.cpp
)


# Specify include directories for the submodule
target_include_directories(vision PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(vision PROPERTIES FOLDER "modules")
