get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Create a library from the submodule's source files
add_library(${LIB_NAME}
    ./src/LinuxScreenshot.cpp
    ./src/MacScreenshot.cpp
    ./src/SaveScreenshot.cpp
    ./src/WinScreenshot.cpp
)

# Set C++20 standard
set_target_properties(${LIB_NAME} PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

set(${LIB_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)  # Path to include directory
set(${LIB_NAME}_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)          # Path to library directory

# Specify include directories for the submodule
target_include_directories(utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(utils PROPERTIES FOLDER "modules")
