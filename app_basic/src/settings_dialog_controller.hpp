#pragma once

#include "settings_dialog_view.hpp"

class ModuleDependencyMatrix;

namespace settings::dialog {
    class IListener {
    public:
        virtual void onClose() = 0;
    };
}

class SettingsDialogController : public settings::IListener {
public:
    SettingsDialogController(SettingsDialogView* view, ModuleDependencyMatrix* dependencyMatrix,
                             settings::dialog::IListener* listener);

    void onSave() override;
    void onCancel() override;
    void show();

private:
    SettingsDialogView* _view;
    ModuleDependencyMatrix* _dependencyMatrix;
    settings::dialog::IListener* _listener;
};