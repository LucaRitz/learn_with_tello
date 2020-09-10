project(app_common)

add_library(${PROJECT_NAME} STATIC)
set(COMMON_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE tello ${FLTK_LIBRARIES})