cmake_minimum_required(VERSION 3.18.2)
project(learn_with_tello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Add libs
add_subdirectory(libs)

set(BUILD_SHARED_LIBS ON)
find_package(OpenCV REQUIRED CONFIG
        PATHS ${CMAKE_BINARY_DIR}/libs/opencv)
unset(BUILD_SHARED_LIBS)

set(CMAKE_HELP_DIR ${CMAKE_SOURCE_DIR}/cmake)
set(RUNTIME_CONTEXT ${CMAKE_BINARY_DIR}/app_basic)
set(MODULE_LIB_DIR ${RUNTIME_CONTEXT}/libs)

# Applications
add_subdirectory(app_basic)
add_subdirectory(app_common)
add_subdirectory(app_common_video)
add_subdirectory(app_modules)