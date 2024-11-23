# Define the library name based on the directory
get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Gather source files from the 'src' directories
file(GLOB_RECURSE SOURCES_2D "${CMAKE_CURRENT_SOURCE_DIR}/2D/src/*.cpp")
file(GLOB_RECURSE SOURCES_3D "${CMAKE_CURRENT_SOURCE_DIR}/3D/src/*.cpp")
file(GLOB_RECURSE SOURCES_INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/interface/src/*.cpp")

# Gather header files from the 'include' directories
file(GLOB_RECURSE HEADERS_2D "${CMAKE_CURRENT_SOURCE_DIR}/2D/include/*.hpp")
file(GLOB_RECURSE HEADERS_3D "${CMAKE_CURRENT_SOURCE_DIR}/3D/include/*.hpp")
file(GLOB_RECURSE HEADERS_INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/interface/include/*.hpp")

# Combine all source files
set(SOURCES ${SOURCES_2D} ${SOURCES_3D} ${SOURCES_INTERFACE})

# Combine all header files (optional, for IDE indexing or completeness)
set(HEADERS ${HEADERS_2D} ${HEADERS_3D} ${HEADERS_INTERFACE})

# Create a library with the gathered source files
add_library(${LIB_NAME} ${SOURCES} ${HEADERS}) # Adding headers is optional

# Set include directories for this library
target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/2D/include
    ${CMAKE_CURRENT_SOURCE_DIR}/3D/include
    ${CMAKE_CURRENT_SOURCE_DIR}/interface/include
)

# Include directories for this library
target_include_directories(${LIB_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include   # Include local project headers
    ${RAYLIB_INCLUDE_DIR}                 # Include raylib headers
    ${COMMON_INCLUDE_DIR}                 # Include raylib headers
    ${GRAPHICS_MANAGER_INCLUDE_DIR}
)

# Link libraries for this target
target_link_libraries(${LIB_NAME} PUBLIC 
    raylibcpp                                 # Link the raylib library
    common
    graphics_manager
)


# Define include and library directories based on the library name
set(${LIB_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/interface/include)  # Path to include directory
set(${LIB_NAME}_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)          # Path to library directory
