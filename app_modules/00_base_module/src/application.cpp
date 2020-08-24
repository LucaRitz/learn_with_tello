#include "application.hpp"

#include <tello/tello.hpp>
#include <tello/logger/logger.hpp>
#include <tello/connection/network.hpp>
#include <common/base_settings.hpp>

using tello::LoggerSettings;
using tello::Logger;
using tello::Network;
using tello::Tello;

#define TELLO_IP_ADDRESS (ip_address)0xC0A80A01

Application::Application() : _baseSettings(std::make_unique<BaseSettings>()) {}

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

    auto* tello = new Tello {TELLO_IP_ADDRESS};
    _baseSettings->setTellos(vector<Tello*> {tello});

    return returnCode;
}

void Application::tearDown() {
    Network::disconnect();
}

void Application::update(ModuleId moduleId, const ISettings* settings) {

}

Fl_Group* Application::getView() const {
    return nullptr;
}