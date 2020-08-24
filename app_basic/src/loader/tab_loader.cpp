#include "tab_loader.hpp"

#include <common/application.hpp>
#include <FL/Fl_Tabs.H>

Fl_Tabs* TabLoader::createTabs(vector<IApplication*>& modules) {
    auto* tabs = new Fl_Tabs(10, 10, 1260, 700);
    for(auto*& module : modules) {
        auto* group = module->getView();
        if (group != nullptr) {
            tabs->add(group);
        }
    }
    tabs->end();
    return tabs;
}