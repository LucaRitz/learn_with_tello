project(02_video_module)

add_library(${PROJECT_NAME} MODULE)

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS} ${FLTK_INCLUDE_DIR})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE app_common_video app_common tello ${OpenCV_LIBS} ${FLTK_LIBRARIES})