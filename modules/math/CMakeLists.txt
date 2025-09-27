
cmake_minimum_required(VERSION 3.10)

project(math)

get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_library(math INTERFACE geometry datastructure)

add_subdirectory(geometry)
add_subdirectory(datastructure)

target_link_libraries(math INTERFACE geometry)

set_target_properties(math PROPERTIES FOLDER "modules/math")
