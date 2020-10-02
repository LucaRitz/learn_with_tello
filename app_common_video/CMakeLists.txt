project(app_common_video)

add_library(${PROJECT_NAME} SHARED)
set_target_properties( ${PROJECT_NAME}
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${RUNTIME_CONTEXT}"
        RUNTIME_OUTPUT_DIRECTORY "${RUNTIME_CONTEXT}"
        )
set(VIDEO_COMMON_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_include_directories(${PROJECT_NAME} PRIVATE ${FFMPEG_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${FLTK_INCLUDE_DIRS})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PUBLIC opengl glad stb
        PRIVATE app_common tello ${FFMPEG_LIBS} ${OpenCV_LIBS} ${FLTK_LIBS})


configure_file(scripts/shader.vs ${CMAKE_BINARY_DIR}/app_basic/scripts/video_common/shader.vs         COPYONLY)
configure_file(scripts/shader.fs ${CMAKE_BINARY_DIR}/app_basic/scripts/video_common/shader.fs         COPYONLY)
configure_file(resources/tello.jpg ${CMAKE_BINARY_DIR}/app_basic/resources/video_common/tello.jpg         COPYONLY)