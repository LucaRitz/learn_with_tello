#include "settings_controller.hpp"

#include <common/base_settings.hpp>
#include "settings_view.hpp"

#define TELLO_IP_ADDRESS (ip_address)0xC0A80A01 // 192.168.10.1

SettingsController::SettingsController(SettingsView* view, std::shared_ptr<BaseSettings> settings) :
    _view(view),
    _baseSettings(std::move(settings)) {

    auto* tello = new Tello {TELLO_IP_ADDRESS};
    _baseSettings->setTellos(vector<Tello*> {tello});
}

Fl_Group* SettingsController::getView() {
    return _view;
}

void SettingsController::save() {
    _view->save(_baseSettings);
}

void SettingsController::updateView() {
    _view->show(_baseSettings);
}

ISettings* SettingsController::settings() const {
    return _baseSettings.get();
}