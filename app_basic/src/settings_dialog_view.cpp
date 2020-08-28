#include "settings_dialog_view.hpp"

#include <common/application.hpp>
#include <common/settings_controller.hpp>
#include <FL/Fl.H>
#include "loader/tab_loader.hpp"

void onCancelPressed(Fl_Widget* widget, void* listener);
void onSavePressed(Fl_Widget* widget, void* listener);

SettingsDialogView::SettingsDialogView(vector<IApplication*>& modules) :
    Fl_Window(500, 300),
    _listener(nullptr),
    _tabs(10, 10, 480, 260),
    _cancelBtn(320, 270, 80, 20, "Cancel"),
    _saveBtn(410, 270, 80, 20, "Save") {
    _tabs.end();
    _tabs.remove(_cancelBtn);
    _tabs.remove(_saveBtn);
    end();
    add(_cancelBtn);
    add(_saveBtn);

    TabLoader::createTabs(_tabs, modules, [](IApplication* appli) {
        return appli->settingsController() ? appli->settingsController()->getView() : nullptr;
    });

    resizable(_tabs);
    set_modal();
    label("Settings");
}

SettingsDialogView::~SettingsDialogView() {
    TabLoader::clear(_tabs);
}

void SettingsDialogView::setListener(settings::IListener* listener) {
    _listener = listener;
    _cancelBtn.callback(onCancelPressed, _listener);
    _saveBtn.callback(onSavePressed, _listener);
}

void onCancelPressed(Fl_Widget* widget, void* listener) {
    static_cast<settings::IListener*>(listener)->onCancel();
}

void onSavePressed(Fl_Widget* widget, void* listener) {
    static_cast<settings::IListener*>(listener)->onSave();
}