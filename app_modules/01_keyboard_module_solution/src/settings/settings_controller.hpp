#pragma once

#include <common/settings_controller.hpp>
#include <memory>

#include "settings_view.hpp"

class KeyboardSettings;

class SettingsController : public ISettingsController, public settings::IListener {
public:
    explicit SettingsController(SettingsView* view, std::shared_ptr<KeyboardSettings> settings);

    [[nodiscard]] Fl_Group* getView() override;
    void save() override;
    void updateView() override;
    [[nodiscard]] ISettings* settings() const override;

    void onFunctionChanged(const FunctionType& functionType) override;

private:
    SettingsView* _view;
    std::shared_ptr<KeyboardSettings> _settings;
};