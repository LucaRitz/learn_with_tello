#pragma once

#include <common/application.hpp>
#include <memory>
#include "settings_controller.hpp"
#include "settings_view.hpp"

using std::shared_ptr;
using std::unique_ptr;

class BaseSettings;

class Application: public IApplication {
public:
    Application();

    [[nodiscard]] ModuleId id() const override;
    [[nodiscard]] string* name() const override;
    [[nodiscard]] vector<ModuleId> dependsOn() const override;
    uint8_t init() override;
    void tearDown() override;
    bool isRunning() override;
    void update(ModuleId moduleId, const ISettings* settings) override;
    [[nodiscard]] Fl_Group* getView() const override;
    ISettingsController* settingsController() override;

private:
    shared_ptr<BaseSettings> _baseSettings;
    unique_ptr<SettingsView> _settingsView;
    unique_ptr<SettingsController> _settingsController;
};