#include "settings_controller.hpp"

#include "keyboard_settings.hpp"
#include "settings_view.hpp"

SettingsController::SettingsController(SettingsView* view, std::shared_ptr<KeyboardSettings> settings) :
    _view(view),
    _settings(std::move(settings)) {
}

Fl_Group* SettingsController::getView() {
    return _view;
}

void SettingsController::save() {
    _view->save(_settings);
}

void SettingsController::updateView() {
    _view->show(_settings);
}

ISettings* SettingsController::settings() const {
    return _settings.get();
}

void SettingsController::onFunctionChanged(const FunctionType& functionType) {

}