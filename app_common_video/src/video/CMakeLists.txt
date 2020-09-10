target_sources(${PROJECT_NAME} PUBLIC
        ${VIDEO_COMMON_INCLUDE}/video/frame_grabber.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber_internal.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber_internal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/H264Decoder.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/H264Decoder.cpp
        )