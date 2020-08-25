#pragma once

#include <FL/Fl_Group.H>
#include <Fl/Fl_Tabs.H>
#include <common/application.hpp>

class IListener {
public:
    virtual ~IListener() = default;
    void onSave(ModuleId moduleId, ISettings* settings);
    void onCancel();
};

class SettingsDialogView : public Fl_Group {
public:
    SettingsDialogView();
    void close() const;
    void showModule(IApplication* application);

private:
    IListener& listener;
    Fl_Tabs _tabs;
};