# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Collider)

# Add the source files
set(SOURCES
    src/Main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(Collider PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC atled)

set_target_properties(Collider PROPERTIES FOLDER "examples")

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/config.json
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/config.json
    COMMENT "Copying config.json to executable directory"
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/config.json
            ${CMAKE_CURRENT_BINARY_DIR}/config.json
    COMMENT "Copying config.json to solution folder"
)
