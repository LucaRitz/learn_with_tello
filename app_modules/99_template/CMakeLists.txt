project(99_template)

add_library(${PROJECT_NAME} SHARED)
set_target_properties( ${PROJECT_NAME}
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${MODULE_LIB_DIR}"
        RUNTIME_OUTPUT_DIRECTORY "${MODULE_LIB_DIR}"
        )

target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIRS})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE app_common tello ${FLTK_LIBS})