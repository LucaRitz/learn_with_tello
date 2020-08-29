#pragma once

#include <common/settings_controller.hpp>
#include <memory>

class SettingsView;
class BaseSettings;

class SettingsController : public ISettingsController {
public:
    explicit SettingsController(SettingsView* view, std::shared_ptr<BaseSettings> settings);

    [[nodiscard]] Fl_Group* getView() override;
    void save() override;
    void updateView() override;
    [[nodiscard]] ISettings* settings() const override;

private:
    SettingsView* _view;
    std::shared_ptr<BaseSettings> _baseSettings;
};