function(download_file url filename)

if(NOT EXISTS ${filename})
    file(DOWNLOAD ${url} ${filename}
    TIMEOUT 60  # seconds
    TLS_VERIFY ON)
endif()

endfunction(download_file)

set(FFMPEG_INSTALL_DIR ${CMAKE_BINARY_DIR}/libs/ffmpeg)
if (WIN32)
    set(FFMPEG_DEV_NAME ffmpeg-20200831-4a11a6f-win64-dev)
    set(FFMPEG_DEV_ARCHIVE_TARGET ${FFMPEG_INSTALL_DIR}/ffmpeg-dev.zip)

    download_file("https://ffmpeg.zeranoe.com/builds/win64/dev/${FFMPEG_DEV_NAME}.zip" ${FFMPEG_DEV_ARCHIVE_TARGET})
    file(ARCHIVE_EXTRACT INPUT ${FFMPEG_DEV_ARCHIVE_TARGET} DESTINATION ${FFMPEG_INSTALL_DIR})

    set(FFMPEG_SHARED_NAME ffmpeg-20200831-4a11a6f-win64-shared)
    set(FFMPEG_SHARED_ARCHIVE_TARGET ${FFMPEG_INSTALL_DIR}/ffmpeg-shared.zip)

    download_file("https://ffmpeg.zeranoe.com/builds/win64/shared/${FFMPEG_SHARED_NAME}.zip" ${FFMPEG_SHARED_ARCHIVE_TARGET})
    file(ARCHIVE_EXTRACT INPUT ${FFMPEG_SHARED_ARCHIVE_TARGET} DESTINATION ${FFMPEG_INSTALL_DIR})
endif()

include(${CMAKE_SOURCE_DIR}/cmake/functions.cmake)
static_lib_file_ending(STATIC_LIB_FILE_ENDING)

set(FFMPEG_DIR "${FFMPEG_INSTALL_DIR}/${FFMPEG_DEV_NAME}")
set(FFMPEG_INCLUDE_DIRS "${FFMPEG_DIR}/include" CACHE INTERNAL "ffmpeg include dir")
set(FFMPEG_LIB_DIR "${FFMPEG_DIR}/lib")
set(FFMPEG_LIBS
        "${FFMPEG_LIB_DIR}/avcodec.${STATIC_LIB_FILE_ENDING}"
        "${FFMPEG_LIB_DIR}/avformat.${STATIC_LIB_FILE_ENDING}"
        "${FFMPEG_LIB_DIR}/avutil.${STATIC_LIB_FILE_ENDING}"
        "${FFMPEG_LIB_DIR}/swscale.${STATIC_LIB_FILE_ENDING}"
        CACHE INTERNAL "ffmpeg libs")