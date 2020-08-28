#include "settings_view.hpp"

#include <string>
#include <common/base_settings.hpp>

SettingsView::SettingsView() :
        Fl_Group(10, 25, 480, 245, "General"),
        _telloIpInput(15, 35, 100, 20) {
    end();
}

void SettingsView::show(std::shared_ptr<BaseSettings>& settings) {
    auto telloIpAsString = std::to_string(settings->tellos().at(0)->ip());
    _telloIpInput.value(telloIpAsString.c_str());
}

void SettingsView::save(std::shared_ptr<BaseSettings>& settings) const {
    std::string telloIpAsString {_telloIpInput.value()};

    ip_address telloIp = std::stoul (telloIpAsString,nullptr,10);

    for (auto* tello : settings->tellos()) {
        delete tello;
    }

    settings->tellos().clear();
    auto* tello = new Tello {telloIp};

    settings->tellos().emplace_back(tello);
}