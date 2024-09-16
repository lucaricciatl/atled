# Create a library from the submodule's source files
add_library(sound
    ./src/sound.cpp
)


# Specify include directories for the submodule
target_include_directories(sound PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(sound PROPERTIES FOLDER "modules")
