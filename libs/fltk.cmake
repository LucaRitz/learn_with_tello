include(${CMAKE_SOURCE_DIR}/cmake/build_external_project.cmake)

build_external_project(
        fltk
        ${CMAKE_CURRENT_BINARY_DIR}/external
        https://github.com/fltk/fltk
        release-1.3.4-2
        -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/fltk
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DOPTION_BUILD_PDF_DOCUMENTATION=OFF
        -DOPTION_BUILD_SHARED_LIBS=TRUE
        -DOPTION_USE_SYSTEM_ZLIB=TRUE
        -DOPTION_USE_SYSTEM_LIBPNG=TRUE
        -DOPTION_USE_SYSTEM_LIBJPEG=TRUE
)