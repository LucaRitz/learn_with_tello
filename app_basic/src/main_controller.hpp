#pragma once

#include "main_view.hpp"
#include "module_dependency_matrix.hpp"
#include "settings_dialog_view.hpp"
#include "settings_dialog_controller.hpp"

class MainController : public mainview::IListener, settings::dialog::IListener {
public:
    MainController(MainView* view, vector<IApplication*>& modules);

    void onSettingsPressed() override;
    void onTabChanged() override;
    void show(int argc, char **argv);
    void onClose() override;

private:
    MainView* _view;
    ModuleDependencyMatrix _dependencyMatrix;
    SettingsDialogView _settingsDialogView;
    SettingsDialogController _settingsDialogController;

    void activateCurrentView();
};