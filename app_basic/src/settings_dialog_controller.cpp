#include "settings_dialog_controller.hpp"

#include <common/settings.hpp>
#include <common/application.hpp>
#include <common/settings_controller.hpp>
#include "module_dependency_matrix.hpp"

SettingsDialogController::SettingsDialogController(SettingsDialogView* view, ModuleDependencyMatrix* dependencyMatrix,
                                                   settings::dialog::IListener* listener) :
    _view(view),
    _dependencyMatrix(dependencyMatrix),
    _listener(listener) {
    _view->setListener(this);
}

void SettingsDialogController::onSave() {
    for(auto* module : _dependencyMatrix->modulesWithSettingsController()) {
        module->settingsController()->save();
    }

    _dependencyMatrix->updateModules();

    _view->hide();
    _listener->onClose();
}

void SettingsDialogController::onCancel() {
    _view->hide();
    _listener->onClose();
}

void SettingsDialogController::show() {
    for (auto* module : _dependencyMatrix->modulesWithSettingsController()) {
        module->settingsController()->updateView();
    }
    _view->show();
}