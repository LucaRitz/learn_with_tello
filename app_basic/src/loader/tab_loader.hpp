#pragma once

#include <vector>

using std::vector;

class Fl_Tabs;
class IApplication;

class TabLoader {
public:
    static Fl_Tabs* createTabs(vector<IApplication*>& modules);
};