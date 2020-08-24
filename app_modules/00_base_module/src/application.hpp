#pragma once

#include <common/application.hpp>
#include <memory>

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
    void update(ModuleId moduleId, const ISettings* settings) override;
    [[nodiscard]] Fl_Group* getView() const override;

private:
    std::unique_ptr<BaseSettings> _baseSettings;
};