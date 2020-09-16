target_sources(${PROJECT_NAME} PUBLIC
        ${VIDEO_COMMON_INCLUDE}/video/frame_grabber.hpp
        ${VIDEO_COMMON_INCLUDE}/video/opencv_widget.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber_internal.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber_internal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/H264Decoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/H264Decoder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/image.h
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv_widget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/shader.h
        ${CMAKE_CURRENT_SOURCE_DIR}/texture.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vertexarray.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vertexarray.h
        ${CMAKE_CURRENT_SOURCE_DIR}/vertexbuffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/vertexbuffer.h
        )