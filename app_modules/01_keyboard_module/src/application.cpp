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
    return ModuleId::KEYBOARD_MODULE;
}

string* Application::name() const {
    return new string {"Keyboard"};
}

vector<ModuleId> Application::dependsOn() const {
    return vector<ModuleId>{ModuleId::BASE};
}

uint8_t Application::init() {
    return 0;
}

void Application::tearDown() {

}

bool Application::isRunning() {
    return false;
}

void Application::update(ModuleId moduleId, ISettings* settings) {
    switch (moduleId) {
        case ModuleId::BASE:
            _baseSettings = dynamic_cast<const BaseSettings*>(settings);
            break;
        default:
            break;
    }
}

Fl_Group* Application::getView() const {
    return _keyboardView.get();
}

ISettingsController* Application::settingsController() {
    return nullptr;
}