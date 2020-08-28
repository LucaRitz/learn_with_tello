#include "settings_dialog_controller.hpp"

#include <common/settings.hpp>
#include <common/application.hpp>
#include <common/settings_controller.hpp>
#include "module_dependency_matrix.hpp"

SettingsDialogController::SettingsDialogController(SettingsDialogView* view, ModuleDependencyMatrix* dependencyMatrix) :
    _view(view),
    _dependencyMatrix(dependencyMatrix) {
    _view->setListener(this);
}

void SettingsDialogController::onSave() {
    for (auto* module : _dependencyMatrix->modulesWithSettingsController()) {
        auto* settings = module->settingsController()->save();
        for (auto* dependent : _dependencyMatrix->getDependents(module->id())) {
            dependent->update(module->id(), settings);
        }
    }
    _view->hide();
}

void SettingsDialogController::onCancel() {
    _view->hide();
}

void SettingsDialogController::show() {
    for (auto* module : _dependencyMatrix->modulesWithSettingsController()) {
        module->settingsController()->updateView();
    }
    _view->show();
}