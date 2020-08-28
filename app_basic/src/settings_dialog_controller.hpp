#pragma once

#include "settings_dialog_view.hpp"

class ModuleDependencyMatrix;

class SettingsDialogController : public settings::IListener {
public:
    SettingsDialogController(SettingsDialogView* view, ModuleDependencyMatrix* dependencyMatrix);

    void onSave() override;
    void onCancel() override;
    void show();

private:
    SettingsDialogView* _view;
    ModuleDependencyMatrix* _dependencyMatrix;
};