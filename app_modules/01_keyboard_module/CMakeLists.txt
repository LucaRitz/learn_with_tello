project(01_keyboard_module)

add_library(${PROJECT_NAME} SHARED)

include(${CMAKE_SOURCE_DIR}/app_common/config.cmake)
appendCommon(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE ${tello_SOURCE_DIR}/include ${FLTK_INCLUDE_DIR})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE ${FLTK_LIBRARIES})