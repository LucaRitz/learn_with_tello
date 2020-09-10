target_sources(${PROJECT_NAME} PUBLIC
        module_load.hpp
        module_load.cpp
        PRIVATE
        tello_video_widget.hpp
        application.hpp
        application.cpp
        keyboard_controller.hpp
        keyboard_controller.cpp
        keyboard_view.hpp
        keyboard_view.cpp
        command_thread.hpp
        command_thread.cpp
        types.hpp
        texture.h
        shader.h
        vertexarray.h
        vertexarray.cpp
        vertexbuffer.h
        vertexbuffer.cpp
        resource.h
        image.h
        )

add_subdirectory(functions)
add_subdirectory(settings)

configure_file(shader.vs        resources/shader.vs         COPYONLY)
configure_file(shader.fs        resources/shader.fs         COPYONLY)
