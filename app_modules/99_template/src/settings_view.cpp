#include "settings_view.hpp"

#include <string>
#include "template_settings.hpp"

SettingsView::SettingsView() :
        Fl_Group(10, 25, 480, 245, "Template"),
        _valueInput(15, 35, 100, 20) {
    end();
}

void SettingsView::show(std::shared_ptr<TemplateSettings>& settings) {
    auto value = std::to_string(settings->aValue());
    _valueInput.value(value.c_str());
}

void SettingsView::save(std::shared_ptr<TemplateSettings>& settings) const {
    std::string aValueAsString {_valueInput.value()};

    int aValue = std::stoi (aValueAsString,nullptr,10);
    settings->aValue(aValue);
}