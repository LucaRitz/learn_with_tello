#include "keyboard_controller.hpp"

#include "application.hpp"
#include "settings/keyboard_settings.hpp"

KeyboardController::KeyboardController(KeyboardView* view, Application* module) :
    _view(view),
    _module(module),
    _commandThread(),
    _isFlying(false) {
    _view->setListener(this);
}

#include <iostream>

void KeyboardController::activate() {
    future<tello::Response> command_response = _module->baseSettings()->tellos().at(0)->command();
    command_response.wait();
    _commandThread.tello(_module->baseSettings()->tellos().at(0));
    _commandThread.mappingFunction(_module->keyboardSettings()->function());
    _commandThread.play();
}

void KeyboardController::deactivate() {
    _commandThread.pause();
    if (_isFlying) {
        std::future<tello::Response> landResponse = _module->baseSettings()->tellos().at(0)->land();
        landResponse.wait();
        if (tello::Status::OK == landResponse.get().status()) {
            _isFlying = false;
        }
    }
}

void KeyboardController::keyPressed(const vector<command::Key>& pressedKeys) {
    _commandThread.activeKeys(pressedKeys);
}

void KeyboardController::takeOffOrLand() {
    if (!_isFlying) {
        std::cout << "Take off" << std::endl;
        std::future<tello::Response> takeOffResponse = _module->baseSettings()->tellos().at(0)->takeoff();
        takeOffResponse.wait();
        if (tello::Status::OK == takeOffResponse.get().status()) {
            _isFlying = true;
        }
        std::cout << "Taken off" << std::endl;
    } else {
        std::future<tello::Response> landResponse = _module->baseSettings()->tellos().at(0)->land();
        landResponse.wait();
        if (tello::Status::OK == landResponse.get().status()) {
            _isFlying = false;
        }
    }
}

Fl_Group* KeyboardController::view() {
    return _view;
}