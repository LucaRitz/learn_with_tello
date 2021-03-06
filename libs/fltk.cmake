include(FetchContent)
set(OPTION_BUILD_PDF_DOCUMENTATION OFF CACHE INTERNAL "")
set(OPTION_BUILD_SHARED_LIBS ON CACHE INTERNAL "")
set(OPTION_USE_SYSTEM_ZLIB ON CACHE INTERNAL "")
set(OPTION_USE_SYSTEM_LIBPNG ON CACHE INTERNAL "")
set(OPTION_USE_SYSTEM_LIBJPEG ON CACHE INTERNAL "")
set(FLTK_BUILD_TEST OFF CACHE INTERNAL "")

FetchContent_Declare(
        fltk
        GIT_REPOSITORY https://github.com/fltk/fltk
        GIT_TAG        e2a249fca99ab91e1bc472e3379c5bcad715221f
)
FetchContent_MakeAvailable(fltk)
unset(OPTION_BUILD_PDF_DOCUMENTATION)
unset(OPTION_BUILD_SHARED_LIBS)
unset(OPTION_USE_SYSTEM_ZLIB)
unset(OPTION_USE_SYSTEM_LIBPNG)
unset(OPTION_USE_SYSTEM_LIBJPEG)
unset(FLTK_BUILD_TEST)

target_compile_definitions(fltk_SHARED PUBLIC -DFL_DLL)
set(FLTK_LIBS fltk_SHARED CACHE INTERNAL "")
set(FLTK_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/_deps/fltk-src/ ${CMAKE_BINARY_DIR}/_deps/fltk-build/ CACHE INTERNAL "")
set(FLTK_BIN_DIR ${CMAKE_BINARY_DIR}/_deps/fltk-build/lib CACHE INTERNAL "")