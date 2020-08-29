#include "module_dependency_matrix.hpp"

#include <algorithm>
#include <common/application.hpp>
#include <common/settings_controller.hpp>

ModuleDependencyMatrix::ModuleDependencyMatrix(vector<IApplication*>& modules) :
    _dependentModules(),
    _modules(modules),
    _settingsController() {
    for(auto*& module : modules) {
        vector<IApplication*> dependents;

        for(auto* dependent : modules) {
            vector<ModuleId> dependentIds = dependent->dependsOn();
            if (std::find(dependentIds.begin(), dependentIds.end(), module->id()) != dependentIds.end()) {
                dependents.push_back(dependent);
            }
        }

        _dependentModules[module->id()] = dependents;

        if (module->settingsController()) {
            _settingsController.push_back(module);
        }
    }
}

void ModuleDependencyMatrix::updateModules() {
    for (auto* module : modulesWithSettingsController()) {
        const auto* settings = module->settingsController()->settings();
        for (auto* dependent : getDependents(module->id())) {
            dependent->update(module->id(), settings);
        }
    }
}

vector<IApplication*> ModuleDependencyMatrix::getDependents(ModuleId moduleId) {
    return _dependentModules.at(moduleId);
}

vector<IApplication*> ModuleDependencyMatrix::modules() {
    return _modules;
}

vector<IApplication*> ModuleDependencyMatrix::modulesWithSettingsController() {
    return _settingsController;
}