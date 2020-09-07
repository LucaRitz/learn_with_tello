#include "application.hpp"

#include "view.hpp"
#include "controller.hpp"
#include "settings_view.hpp"
#include "settings_controller.hpp"
#include "template_settings.hpp"

using tello::Tello;
using tello::Response;

Application::Application() :
    _baseSettings(nullptr),
    _settings(std::make_shared<TemplateSettings>()),
    _view(std::make_unique<View>()),
    _controller(std::make_unique<Controller>(_view.get(), this)),
    _settingsView(std::make_unique<SettingsView>()),
    _settingsController(std::make_unique<SettingsController>(_settingsView.get(), _settings)) {
}

ModuleId Application::id() const {
    return ModuleId::TEMPLATE;
}

string* Application::name() const {
    return new string {"Template"};
}

vector<ModuleId> Application::dependsOn() const {
    return vector<ModuleId>{ModuleId::BASE};
}

uint8_t Application::init() {
    return 0;
}

void Application::tearDown() {
    // TODO: Tear-Down
}

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
    return _controller.get();
}

ISettingsController* Application::settingsController() {
    return _settingsController.get();
}

const BaseSettings* Application::baseSettings() {
    return _baseSettings;
}

shared_ptr<TemplateSettings> Application::settings() {
    return _settings;
}