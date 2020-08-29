project(app_basic)

add_executable(${PROJECT_NAME})


include(${CMAKE_SOURCE_DIR}/app_common/config.cmake)
appendCommon(${PROJECT_NAME})

add_custom_target(copy_modules COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/copy_modules.cmake)
add_custom_target(copy_libraries COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/copy_libraries.cmake)
add_dependencies(${PROJECT_NAME} copy_modules copy_libraries)

target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE tello ${FLTK_LIBRARIES})