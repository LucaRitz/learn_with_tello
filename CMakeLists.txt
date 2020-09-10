cmake_minimum_required(VERSION 3.18.2)
project(learn_with_tello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Add libs
add_subdirectory(libs)
find_package(fltk REQUIRED)
add_definitions(-DFL_DLL)

set(BUILD_SHARED_LIBS ON)
find_package(OpenCV REQUIRED CONFIG
        PATHS ${CMAKE_BINARY_DIR}/libs/opencv)
unset(BUILD_SHARED_LIBS)

# Applications
add_subdirectory(app_basic)
add_subdirectory(app_common)
add_subdirectory(app_common_video)
add_subdirectory(app_modules)