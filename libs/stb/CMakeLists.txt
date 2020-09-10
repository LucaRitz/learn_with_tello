project(stb LANGUAGES CXX)

add_subdirectory(stb_image)

add_library(stb INTERFACE)

target_link_libraries (stb INTERFACE stb_image)

target_include_directories (stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
