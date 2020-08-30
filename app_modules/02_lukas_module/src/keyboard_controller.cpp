#include "keyboard_controller.hpp"

KeyboardController::KeyboardController(KeyboardView* view, Application* module) :
    _view(view),
    _module(module) {
    _view->setListener(this);
}

#include <iostream>

void KeyboardController::activate() {
    std::cout << "Activate Lukas view" << std::endl;
}

void KeyboardController::deactivate() {
    std::cout << "Deactivate Lukas view" << std::endl;
}

Fl_Group* KeyboardController::view() {
    return _view;
}