#pragma once

#include <common/application.hpp>
#include <common/base_settings.hpp>
#include <memory>

using std::unique_ptr;
using std::shared_ptr;

class KeyboardView;
class KeyboardController;
class KeyboardSettings;
class SettingsController;
class SettingsView;

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
    shared_ptr<KeyboardSettings> keyboardSettings();

private:
    const BaseSettings* _baseSettings;
    shared_ptr<KeyboardSettings> _keyboardSettings;
    const unique_ptr<KeyboardView> _keyboardView;
    const unique_ptr<KeyboardController> _keyboardController;
    unique_ptr<SettingsView> _settingsView;
    unique_ptr<SettingsController> _settingsController;
};