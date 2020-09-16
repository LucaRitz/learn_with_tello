target_sources(${PROJECT_NAME} PUBLIC
        ${COMMON_INCLUDE}/common/application.hpp
        ${COMMON_INCLUDE}/common/base_controller.hpp
        ${COMMON_INCLUDE}/common/base_settings.hpp
        ${COMMON_INCLUDE}/common/macro_definition.hpp
        ${COMMON_INCLUDE}/common/settings.hpp
        ${COMMON_INCLUDE}/common/settings_controller.hpp
        ${COMMON_INCLUDE}/common/worker.hpp

        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/base_settings.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/worker.cpp
        )