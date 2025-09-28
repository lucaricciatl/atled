set(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})
enable_testing()
add_executable(${LIB_NAME} ${TEST_SOURCES})

target_link_libraries(${LIB_NAME} PUBLIC gtest)

set_target_properties(${LIB_NAME} PROPERTIES FOLDER "test")
