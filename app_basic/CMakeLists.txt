project(app_basic)

add_executable(${PROJECT_NAME})
set_target_properties( ${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        )

target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIRS})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE app_common tello ${FLTK_LIBS})

configure_file(${CMAKE_SOURCE_DIR}/cmake/copy_libraries.cmake ${CMAKE_BINARY_DIR}/copy_libraries_gen.cmake @ONLY)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/copy_libraries_gen.cmake)