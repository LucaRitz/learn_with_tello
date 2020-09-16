#include "keyboard_controller.hpp"

#include "application.hpp"
#include "settings/keyboard_settings.hpp"

KeyboardController::KeyboardController(KeyboardView* view, Application* module) :
    _view(view),
    _module(module),
    _workUiExecutor(),
    _workExecutor(),
    _commandWorker(),
    _videoWorker(*this),
    _isFlying(false),
    _takeoffWorker(_module, _isFlying) {
    _view->setListener(this);
    _workExecutor.append(_commandWorker);
    _workUiExecutor.append(_videoWorker);
}

#include <iostream>

void KeyboardController::activate() {
    future<tello::Response> command_response = _module->baseSettings()->tellos().at(0)->command();
    command_response.wait();
    _commandWorker.tello(_module->baseSettings()->tellos().at(0));
    _commandWorker.mappingFunction(_module->keyboardSettings()->function());
    _videoWorker.tello(_module->baseSettings()->tellos().at(0));

    _workUiExecutor.play();
    _workExecutor.play();
}

void KeyboardController::deactivate() {
    _workUiExecutor.pause();
    _workExecutor.pause();
    if (_isFlying) {
        std::future<tello::Response> landResponse = _module->baseSettings()->tellos().at(0)->land();
        landResponse.wait();
        if (tello::Status::OK == landResponse.get().status()) {
            _isFlying = false;
        }
    }
}

void KeyboardController::keyPressed(const vector<command::Key>& pressedKeys) {
    _commandWorker.activeKeys(pressedKeys);
}

void KeyboardController::takeOffOrLand() {
    if (!_takeoffWorker.attached()) {
        _workExecutor.append(_takeoffWorker, true);
    }
}

void KeyboardController::picture(cv::Mat& picture) {
    _view->picture(picture);
}

Fl_Group* KeyboardController::view() {
    return _view;
}