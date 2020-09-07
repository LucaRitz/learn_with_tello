#include "settings_controller.hpp"

#include "template_settings.hpp"
#include "settings_view.hpp"

SettingsController::SettingsController(SettingsView* view, std::shared_ptr<TemplateSettings> settings) :
    _view(view),
    _settings(std::move(settings)) {
    _settings->aValue(10);
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