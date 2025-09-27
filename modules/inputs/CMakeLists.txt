# Create a library from the submodule's source files
add_library(inputs
    ./src/RaylibKeyboard.cpp
    ./src/RaylibMouse.cpp
    ./src/InputManagerBuilder.cpp
    ./src/InputManager.cpp
    ./src/AtledMouseLinux.cpp
    ./src/AtledMouseWindows.cpp
)

# Specify include directories for the submodule
target_include_directories(inputs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/factories
    ${CMAKE_CURRENT_SOURCE_DIR}/include/implementation
)
set_target_properties(inputs PROPERTIES FOLDER "modules")
target_link_libraries(inputs PRIVATE external)

if(BUILD_TESTING)
    # Enable testing features in CMake
    enable_testing()

    # Create the test executable
    add_executable(InputLibTests main.cpp)

    # Add the test. Note: The recommended syntax is to specify a NAME and a COMMAND.
    add_test(NAME InputLibTests COMMAND InputLibTests)
endif()