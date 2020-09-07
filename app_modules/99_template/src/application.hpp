#pragma once

#include <common/application.hpp>
#include <common/base_settings.hpp>
#include <memory>

using std::unique_ptr;
using std::shared_ptr;

class View;
class Controller;
class TemplateSettings;
class SettingsView;
class SettingsController;

class Application: public IApplication {
public:
    Application();

    [[nodiscard]] ModuleId id() const override;
    [[nodiscard]] string* name() const override;
    [[nodiscard]] vector<ModuleId> dependsOn() const override;
    uint8_t init() override;
    void tearDown() override;
    void update(ModuleId moduleId, const ISettings* settings) override;
    [[nodiscard]] BaseController* controller() override;
    ISettingsController* settingsController() override;

    const BaseSettings* baseSettings();
    shared_ptr<TemplateSettings> settings();

private:
    const BaseSettings* _baseSettings;
    shared_ptr<TemplateSettings> _settings;
    const unique_ptr<View> _view;
    const unique_ptr<Controller> _controller;
    unique_ptr<SettingsView> _settingsView;
    unique_ptr<SettingsController> _settingsController;
};