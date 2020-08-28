#include "keyboard_controller.hpp"

KeyboardController::KeyboardController(KeyboardView* view, Application* module) :
    _view(view),
    _module(module) {
    _view->setListener(this);
}