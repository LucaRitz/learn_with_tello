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
        command_worker.hpp
        command_worker.cpp
        video_worker.hpp
        video_worker.cpp
        types.hpp
        resource.h
        takeoff_worker.hpp
        takeoff_worker.cpp
        )

add_subdirectory(functions)
add_subdirectory(settings)
