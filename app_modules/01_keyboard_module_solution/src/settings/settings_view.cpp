#include "settings_view.hpp"

#include "keyboard_settings.hpp"

Fl_Menu_Item choices[] = {
        {"Linear"},
        {nullptr}};

static void onLinearFunctionPressed(Fl_Widget* widget, void* listener);

SettingsView::SettingsView() :
        Fl_Group(10, 25, 480, 245, "Keyboard - Solution"),
        _listener(nullptr),
        _functionChoice(15, 35, 100, 20) {
    _functionChoice.value(choices);
    end();
}

void SettingsView::show(std::shared_ptr<KeyboardSettings>& settings) {

}

void SettingsView::save(std::shared_ptr<KeyboardSettings>& settings) const {

}

void SettingsView::setListener(settings::IListener *listener) {
    _listener = listener;
    choices[0].callback(onLinearFunctionPressed, _listener);
}

void onLinearFunctionPressed(Fl_Widget* widget, void* listener) {
    static_cast<settings::IListener*>(listener)->onFunctionChanged(FunctionType::LINEAR);
}