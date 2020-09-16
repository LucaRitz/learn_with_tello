project(01_keyboard_module_solution)

add_library(${PROJECT_NAME} MODULE)

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS} ${FLTK_INCLUDE_DIRS})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE app_common tello ${OpenCV_LIBS} ${FLTK_LIBS} opengl glad stb)


configure_file(scripts/shader.vs ${CMAKE_BINARY_DIR}/app_basic/scripts/01/shader.vs         COPYONLY)
configure_file(scripts/shader.fs ${CMAKE_BINARY_DIR}/app_basic/scripts/01/shader.fs         COPYONLY)
configure_file(resources/container.jpg ${CMAKE_BINARY_DIR}/app_basic/resources/01/container.jpg         COPYONLY)