#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class IApplication;
enum class ModuleId;

class ModuleDependencyMatrix {
public:
    explicit ModuleDependencyMatrix(vector<IApplication*>& modules);

    vector<IApplication*> getDependents(ModuleId moduleId);
    vector<IApplication*> modules();
    vector<IApplication*> modulesWithSettingsController();

private:
    unordered_map<ModuleId, vector<IApplication*>> _dependentModules;
    vector<IApplication*> _modules;
    vector<IApplication*> _settingsController;
};