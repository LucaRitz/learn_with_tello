include(${CMAKE_SOURCE_DIR}/cmake/functions.cmake)

static_lib_file_ending(STATIC_LIB_FILE_ENDING)

set(FLTK_INCLUDE_DIR ${CMAKE_BINARY_DIR}/libs/fltk/include)
file(GLOB FLTK_LIBRARIES ${CMAKE_BINARY_DIR}/libs/fltk/lib/*_SHARED*.${STATIC_LIB_FILE_ENDING})