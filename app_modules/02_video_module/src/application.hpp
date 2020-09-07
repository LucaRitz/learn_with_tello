#pragma once

#include <common/application.hpp>
#include <common/base_settings.hpp>
#include <memory>

using std::unique_ptr;

class VideoView;
class VideoController;

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

private:
    const BaseSettings* _baseSettings;
    const unique_ptr<VideoView> _videoView;
    const unique_ptr<VideoController> _videoController;
};