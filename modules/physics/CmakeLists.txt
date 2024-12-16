

cmake_minimum_required(VERSION 3.10)
get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${LIB_NAME})


add_library(${LIB_NAME} INTERFACE)


add_subdirectory(space3D)
add_subdirectory(physics_manager)
add_subdirectory(particles)
add_subdirectory(collisions)
add_subdirectory(body)


target_link_libraries(${LIB_NAME} INTERFACE space3D physics_manager body math)

set_target_properties(${LIB_NAME} PROPERTIES FOLDER "modules")



## Define the library name based on the directory
#get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#
## Gather source files from the 'src' directories
#file(GLOB_RECURSE SOURCES_2D "${CMAKE_CURRENT_SOURCE_DIR}/body/src/*.cpp")
#file(GLOB_RECURSE SOURCES_3D "${CMAKE_CURRENT_SOURCE_DIR}/space3D/src/*.cpp")
#
## Gather header files from the 'include' directories
#file(GLOB_RECURSE HEADERS_2D "${CMAKE_CURRENT_SOURCE_DIR}/body/include/*.hpp")
#file(GLOB_RECURSE HEADERS_3D "${CMAKE_CURRENT_SOURCE_DIR}/space3D/include/*.hpp")
#
## Combine all source files
#set(SOURCES ${SOURCES_2D} ${SOURCES_3D} ${SOURCES_INTERFACE})
#
## Combine all header files (optional, for IDE indexing or completeness)
#set(HEADERS ${HEADERS_2D} ${HEADERS_3D} ${HEADERS_INTERFACE})
#
## Create a library with the gathered source files
#add_library(${LIB_NAME} ${SOURCES} ${HEADERS}) # Adding headers is optional
#
## Specify include directories for the physics target
#target_include_directories(${LIB_NAME} PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/body/include
#    ${CMAKE_CURRENT_SOURCE_DIR}/collisions/include
#    ${CMAKE_CURRENT_SOURCE_DIR}/space3D/include
#    ${RAYLIB_INCLUDE_DIR}                 # Include raylib headers
#)
#
#
## Link libraries for this target
#target_link_libraries(${LIB_NAME} PUBLIC 
#    raylibcpp                                 # Link the raylib library
#)
#
#
## Define include and library directories based on the library name
#set(${LIB_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/space3D/include 
#    ${CMAKE_CURRENT_SOURCE_DIR}/body/include
#    ${CMAKE_CURRENT_SOURCE_DIR}/collisions/include
#    )  # Path to include directory
#set(${LIB_NAME}_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)          # Path to library directory
#
## Set properties for the physics target
#set_target_properties(${LIB_NAME} PROPERTIES 
#    FOLDER "modules"
#    CXX_STANDARD 17                # Ensure C++17 is used
#    CXX_STANDARD_REQUIRED ON       # Enforce C++17
#)