cmake_minimum_required(VERSION 3.15)
project(learn_with_tello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Add libs
add_subdirectory(libs)
find_package(fltk REQUIRED)

set(BUILD_SHARED_LIBS OFF)
set(OpenCV_DIR ${CMAKE_BINARY_DIR}/libs/opencv/x64/vc16/staticlib)
find_package(OpenCV REQUIRED)

# Applications
add_subdirectory(app_basic)
add_subdirectory(app_common)
add_subdirectory(app_modules)