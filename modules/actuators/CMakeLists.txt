# Create a library from the submodule's source files
add_library(actuators
    ./src/actuators.cpp
)


# Specify include directories for the submodule
target_include_directories(actuators PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include

)
set_target_properties(actuators PROPERTIES FOLDER "modules")
