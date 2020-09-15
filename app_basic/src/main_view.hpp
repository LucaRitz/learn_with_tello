#pragma once

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <vector>

using std::vector;

class IApplication;

namespace mainview {
    class IListener {
    public:
        virtual ~IListener() = default;

        virtual void onSettingsPressed() = 0;
        virtual void onTabChanged() = 0;
    };
}

#include <iostream>
class MainView : public Fl_Window {
public:
    MainView();
    ~MainView() override;

    void setModules(vector<IApplication*>& modules);
    void setListener(mainview::IListener* listener);

    Fl_Widget* activeView();

private:
    mainview::IListener* _listener;
    Fl_Tabs _tabs;
    Fl_Menu_Bar _menuBar;
};