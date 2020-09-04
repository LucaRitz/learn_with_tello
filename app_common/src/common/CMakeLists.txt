target_sources(${PROJECT_NAME} PUBLIC
        ${COMMON_INCLUDE}/common/application.hpp
        ${COMMON_INCLUDE}/common/base_controller.hpp
        ${COMMON_INCLUDE}/common/base_settings.hpp
        ${COMMON_INCLUDE}/common/frame_grabber.hpp
        ${COMMON_INCLUDE}/common/keyboard_settings.hpp
        ${COMMON_INCLUDE}/common/macro_definition.hpp
        ${COMMON_INCLUDE}/common/settings.hpp
        ${COMMON_INCLUDE}/common/settings_controller.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/base_settings.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/frame_grabber.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/keyboard_settings.cpp
        )