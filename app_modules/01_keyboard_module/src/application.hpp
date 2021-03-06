#pragma once

#include <common/application.hpp>
#include <common/base_settings.hpp>
#include <memory>

using std::unique_ptr;

class KeyboardView;
class KeyboardController;

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

private:
    const BaseSettings* _baseSettings;
    const unique_ptr<KeyboardView> _keyboardView;
    const unique_ptr<KeyboardController> _keyboardController;
};