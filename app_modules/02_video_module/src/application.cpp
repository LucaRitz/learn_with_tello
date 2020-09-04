#include "application.hpp"

#include <tello/tello.hpp>
#include "keyboard_view.hpp"
#include "keyboard_controller.hpp"

using tello::Tello;
using tello::Response;

Application::Application() :
    _baseSettings(nullptr),
    _keyboardView(std::make_unique<KeyboardView>()),
    _keyboardController(std::make_unique<KeyboardController>(_keyboardView.get(), this)){
}

ModuleId Application::id() const {
    return ModuleId::VIDEO_MODULE;
}

string* Application::name() const {
    return new string {"Video"};
}

vector<ModuleId> Application::dependsOn() const {
    return vector<ModuleId>{ModuleId::BASE};
}

uint8_t Application::init() {
    return 0;
}

void Application::tearDown() {

}

#include <iostream>
void Application::update(ModuleId moduleId, const ISettings* settings) {
    switch (moduleId) {
        case ModuleId::BASE: {
            _baseSettings = dynamic_cast<const BaseSettings*>(settings);
            std::cout << "Update settings in module 3: " << _baseSettings->tellos().at(0)->ip() << std::endl;
            break;
        }
        default:
            break;
    }
}

BaseController* Application::controller() {
    return _keyboardController.get();
}

ISettingsController* Application::settingsController() {
    return nullptr;
}

const BaseSettings* Application::baseSettings() {
    return _baseSettings;
}