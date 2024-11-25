# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(common)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set paths for headers and libraries
set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)  # Path to the include directory
set(COMMON_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)          # Path to the library directory (if needed)

# Include the header files directory
include_directories(${COMMON_INCLUDE_DIR})

# Source files for the library
set(SOURCES 
    src/Point2D.cpp
    # Add more source files here if needed
)

# Create the library target
add_library(${PROJECT_NAME} ${SOURCES})

# Set the module folder for organizing in IDEs
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "modules")

# Add include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC ${COMMON_INCLUDE_DIR})

# If this library depends on other libraries, link them here
# Example:
# target_link_libraries(${PROJECT_NAME} PUBLIC some_dependency_library)

# Set the library output directory (optional)
set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${COMMON_LIB_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${COMMON_LIB_DIR}
)
