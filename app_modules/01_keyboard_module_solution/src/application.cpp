#include "application.hpp"

#include "settings/keyboard_settings.hpp"
#include "settings/settings_view.hpp"
#include "settings/settings_controller.hpp"
#include "keyboard_view.hpp"
#include "keyboard_controller.hpp"
#include "functions/linear_function.hpp"

using tello::Tello;
using tello::Response;

Application::Application() :
    _baseSettings(nullptr),
    _keyboardSettings(std::make_shared<KeyboardSettings>()),
    _keyboardView(std::make_unique<KeyboardView>()),
    _keyboardController(std::make_unique<KeyboardController>(_keyboardView.get(), this)),
    _settingsView(std::make_unique<SettingsView>()),
    _settingsController(std::make_unique<SettingsController>(_settingsView.get(), _keyboardSettings)) {
}

ModuleId Application::id() const {
    return ModuleId::KEYBOARD_SOLUTION_MODULE;
}

string* Application::name() const {
    return new string {"Keyboard - Solution"};
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
    return _settingsController.get();
}

const BaseSettings* Application::baseSettings() {
    return _baseSettings;
}

shared_ptr<KeyboardSettings> Application::keyboardSettings() {
    return _keyboardSettings;
}