# Define the library name based on the directory
get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Gather source files from the 'src' directory
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Gather header files from the 'include' directory
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
# Gather header files from the 'include' directory
file(GLOB_RECURSE HEADERS_INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/interface/include/*.hpp")

# Create a library with the gathered source files
add_library(${LIB_NAME} ${SOURCES})

# Include directories for this library
target_include_directories(${LIB_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/interface   
    ${CMAKE_CURRENT_SOURCE_DIR}/include   
    ${CMAKE_CURRENT_SOURCE_DIR}/interface/include   
    ${RAYLIB_INCLUDE_DIR}                
    ${MATH_INCLUDE_DIR}                 
    ${SHADER_INCLUDE_DIR}                 
    ${CMAKE_CURRENT_SOURCE_DIR}/../shader/include
)

# Link libraries for this target
target_link_libraries(${LIB_NAME} PUBLIC 
    raylibcpp    
    ${SHADER_LIB_DIR}   
    ${MATH_LIB_DIR}                             
)
# Optionally link this library with other dependencies
# target_link_libraries(${LIB_NAME} <other_dependencies>)

# Add to the main graphics library if needed
# Define include and library directories based on the library name
set(${LIB_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)  # Path to include directory
set(${LIB_NAME}_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)          # Path to library directory


set_target_properties(${LIB_NAME} PROPERTIES FOLDER "modules")