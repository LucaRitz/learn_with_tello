#include "main_controller.hpp"

#include <FL/fl_ask.H>
#include <common/application.hpp>

MainController::MainController(MainView* view, vector<IApplication*>& modules) :
    _view(view),
    _dependencyMatrix(modules),
    _settingsDialogView(modules),
    _settingsDialogController(&_settingsDialogView, &_dependencyMatrix) {
    _view->setListener(this);
    _view->setModules(modules);
}

void MainController::onSettingsPressed() {
    bool hasRunningModule = false;
    for(auto* module : _dependencyMatrix.modules()) {
        hasRunningModule |= module->isRunning();
    }

    if (hasRunningModule) {
        fl_alert("There are running modules. Please stop first");
        return;
    }

    _settingsDialogController.show();
}

void MainController::show(int argc, char **argv) {
    _view->show(argc, argv);
}

