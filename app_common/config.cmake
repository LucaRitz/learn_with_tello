function(appendCommon TARGET)
    target_sources(${TARGET} PRIVATE
            ${CMAKE_SOURCE_DIR}/app_common/common/application.hpp
            ${CMAKE_SOURCE_DIR}/app_common/common/settings_controller.hpp
            ${CMAKE_SOURCE_DIR}/app_common/common/settings.hpp
            ${CMAKE_SOURCE_DIR}/app_common/common/macro_definition.hpp
            ${CMAKE_SOURCE_DIR}/app_common/common/base_settings.hpp
            ${CMAKE_SOURCE_DIR}/app_common/common/base_settings.cpp
            )
endfunction()