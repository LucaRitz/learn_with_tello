project(02_video_module)

add_library(${PROJECT_NAME} SHARED)
set_target_properties( ${PROJECT_NAME}
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${MODULE_LIB_DIR}"
        RUNTIME_OUTPUT_DIRECTORY "${MODULE_LIB_DIR}"
        )

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS} ${FLTK_INCLUDE_DIRS})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE app_common_video app_common tello ${OpenCV_LIBS} ${FLTK_LIBS})