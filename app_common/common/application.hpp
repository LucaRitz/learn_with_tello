#pragma once

#include <string>
#include <vector>

#include "settings.hpp"

using std::string;
using std::vector;

class Fl_Group;

enum class ModuleId {
    BASE,
    KEYBOARD_MODULE
};

class IApplication {
public:
    [[nodiscard]] virtual ModuleId id() const = 0;
    [[nodiscard]] virtual string* name() const = 0;
    [[nodiscard]] virtual vector<ModuleId> dependsOn() const = 0;
    virtual uint8_t init() = 0;
    virtual void tearDown() = 0;
    virtual void update(ModuleId moduleId, const ISettings* settings) = 0;
    [[nodiscard]] virtual Fl_Group* getView() const = 0;

    void addDependent(IApplication* dependent);

private:
    vector<IApplication*> _dependentModules;
};