# Create a library from the submodule's source files
add_library(filesystem
    src/FilesystemManager.cpp
)

# Specify include directories for the submodule
target_include_directories(filesystem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(filesystem PROPERTIES FOLDER "modules")
