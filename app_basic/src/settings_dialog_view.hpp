#pragma once

#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <vector>

using std::vector;

class IApplication;

namespace settings {
    class IListener {
    public:
        virtual ~IListener() = default;
        virtual void onSave() = 0;
        virtual void onCancel() = 0;
    };
}

class SettingsDialogView : public Fl_Window {
public:
    explicit SettingsDialogView(vector<IApplication*>& modules);
    ~SettingsDialogView() override;

    void setListener(settings::IListener* listener);

private:
    settings::IListener* _listener;
    Fl_Tabs _tabs;
    Fl_Button _cancelBtn;
    Fl_Button _saveBtn;
};