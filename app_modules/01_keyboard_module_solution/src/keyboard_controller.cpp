#include "keyboard_controller.hpp"

KeyboardController::KeyboardController(KeyboardView* view, Application* module) :
    _view(view),
    _module(module) {
    _view->setListener(this);
}

#include <iostream>

void KeyboardController::activate() {
    std::cout << "Activate Keyboard view" << std::endl;
}

void KeyboardController::deactivate() {
    std::cout << "Deactivate Keyboard view" << std::endl;
}

Fl_Group* KeyboardController::view() {
    return _view;
}