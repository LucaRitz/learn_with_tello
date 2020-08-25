#pragma once

#include <vector>
#include <functional>

using std::vector;

class Fl_Tabs;
class Fl_Group;
class IApplication;

class TabLoader {
public:
    static void createTabs(Fl_Tabs& tabs, vector<IApplication*>& modules, std::function<Fl_Group*(IApplication*)>&& getView);
};