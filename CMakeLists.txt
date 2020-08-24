cmake_minimum_required(VERSION 3.15)
project(learn_with_tello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Add libs
add_subdirectory(libs)
find_package(fltk REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/app_common)

# Applications
add_subdirectory(app_basic)
add_subdirectory(app_modules)