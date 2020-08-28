#include "application.hpp"

#include <tello/logger/logger.hpp>
#include <tello/connection/network.hpp>
#include <common/base_settings.hpp>

using tello::LoggerSettings;
using tello::Logger;
using tello::Network;
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
    Logger::initialize(settings);

    const bool isConnected = Network::connect();
    short returnCode = isConnected ? 0 : 1;

    return returnCode;
}

void Application::tearDown() {
    Network::disconnect();
}

bool Application::isRunning() {
    return false;
}

void Application::update(ModuleId moduleId, ISettings* settings) {
    // NOOP
}

Fl_Group* Application::getView() const {
    return nullptr;
}

ISettingsController* Application::settingsController() {
    return _settingsController.get();
}