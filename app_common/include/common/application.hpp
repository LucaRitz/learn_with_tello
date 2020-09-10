#pragma once

#include <string>
#include <vector>

#include "settings.hpp"
#include "base_controller.hpp"

using std::string;
using std::vector;

class Fl_Group;
class ISettingsController;

enum class ModuleId {
    BASE,
    KEYBOARD_MODULE,
    KEYBOARD_SOLUTION_MODULE,
    VIDEO_MODULE,
    VIDEO_TEST_MODULE,

    TEMPLATE
};

class IApplication {
public:
    virtual ~IApplication() = default;
    [[nodiscard]] virtual ModuleId id() const = 0;
    [[nodiscard]] virtual string* name() const = 0;
    [[nodiscard]] virtual vector<ModuleId> dependsOn() const = 0;
    virtual uint8_t init() = 0;
    virtual void tearDown() = 0;
    virtual void update(ModuleId moduleId, const ISettings* settings) = 0;
    [[nodiscard]] virtual BaseController* controller() = 0;
    virtual ISettingsController* settingsController() = 0;
};