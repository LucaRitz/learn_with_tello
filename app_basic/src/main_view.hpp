#pragma once

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <vector>

using std::vector;

class IApplication;

class IListener {
public:
    virtual ~IListener() = default;

    virtual void onSettingsPressed() const = 0;
};

class MainView : public Fl_Group {
public:
    MainView();
    void setModules(vector<IApplication*>& modules);
    void setListener(IListener* listener);
    void show(int argc, char **argv);

private:
    IListener* _listener;
    Fl_Window _window;
    Fl_Tabs _tabs;
    Fl_Menu_Bar _menuBar;
};