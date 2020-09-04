target_sources(${PROJECT_NAME} PUBLIC
        module_load.hpp
        module_load.cpp
        PRIVATE
        application.hpp
        application.cpp
        keyboard_controller.hpp
        keyboard_controller.cpp
        keyboard_view.hpp
        keyboard_view.cpp
        command_thread.hpp
        command_thread.cpp
        types.hpp
        )

add_subdirectory(functions)