target_sources(${PROJECT_NAME} PUBLIC
        module_load.hpp
        module_load.cpp

        PRIVATE
        application.hpp
        application.cpp
        controller.hpp
        controller.cpp
        view.hpp
        view.cpp
        settings_controller.hpp
        settings_controller.cpp
        settings_view.hpp
        settings_view.cpp
        template_settings.hpp
        template_settings.cpp
        )