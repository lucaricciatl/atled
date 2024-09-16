# Create a library from the submodule's source files
add_library(sensors
    ./src/sensors.cpp
)


# Specify include directories for the submodule
target_include_directories(sensors PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(sensors PROPERTIES FOLDER "modules")
