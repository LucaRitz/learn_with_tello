if (WIN32)
    add_subdirectory(windows)
endif()

target_sources(${PROJECT_NAME} PRIVATE
        library_loader.hpp
        loader.hpp
        loader.cpp
        tab_loader.hpp
        tab_loader.cpp
        )