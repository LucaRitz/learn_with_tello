#include "main_controller.hpp"

#include <common/application.hpp>

MainController::MainController(MainView* view, vector<IApplication*>& modules) :
    _view(view),
    _dependencyMatrix(modules),
    _settingsDialogView(modules),
    _settingsDialogController(&_settingsDialogView, &_dependencyMatrix, this) {
    _view->setListener(this);
    _view->setModules(modules);
    _dependencyMatrix.updateModules();
    activateCurrentView();
}

void MainController::onSettingsPressed() {
    for(auto* module : _dependencyMatrix.modules()) {
        if (module->controller()) {
            module->controller()->deactivate();
        }
    }

    _settingsDialogController.show();
}

void MainController::onTabChanged() {
    for(auto* module : _dependencyMatrix.modules()) {
        if (module->controller()) {
            module->controller()->deactivate();
        }
    }
    activateCurrentView();
}

void MainController::show(int argc, char **argv) {
    _view->show(argc, argv);
}

void MainController::onClose() {
    activateCurrentView();
}

void MainController::activateCurrentView() {
    auto* activeView = _view->activeView();
    for(auto* module : _dependencyMatrix.modules()) {
        if (module->controller()) {
            auto* controller = module->controller();
            if (controller->view() == activeView) {
                controller->activate();
            }
        }
    }
}