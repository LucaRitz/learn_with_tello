#include "application.hpp"

#include <tello/logger/logger_interface.hpp>
#include <tello/connection/tello_network.hpp>
#include <common/base_settings.hpp>

using tello::LoggerSettings;
using tello::LoggerInterface;
using tello::TelloNetwork;
using tello::Tello;

Application::Application() :
    _baseSettings(std::make_unique<BaseSettings>()),
    _settingsView(std::make_unique<SettingsView>()),
    _settingsController(std::make_unique<SettingsController>(_settingsView.get(), _baseSettings)) {}

ModuleId Application::id() const {
    return ModuleId::BASE;
}

string* Application::name() const {
    return new string { "General" };
}

vector<ModuleId> Application::dependsOn() const {
    return vector<ModuleId>{};
}

uint8_t Application::init() {
    LoggerSettings settings{"./log/command_log.log", "./log/video_log.log", "./log/status_log.log"};
    LoggerInterface::initialize(settings);

    const bool isConnected = TelloNetwork::connect();
    short returnCode = isConnected ? 0 : 1;

    return returnCode;
}

void Application::tearDown() {
    TelloNetwork::disconnect();
}

void Application::update(ModuleId moduleId, const ISettings* settings) {
    // NOOP
}

BaseController* Application::controller() {
    return nullptr;
}

ISettingsController* Application::settingsController() {
    return _settingsController.get();
}