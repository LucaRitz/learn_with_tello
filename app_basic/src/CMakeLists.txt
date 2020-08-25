add_subdirectory(loader)

target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/settings_dialog_view.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/settings_dialog_view.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/settings_dialog_controller.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/settings_dialog_controller.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main_view.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main_view.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main_controller.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main_controller.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/module_dependency_matrix.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/module_dependency_matrix.cpp
        )