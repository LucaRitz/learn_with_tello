#include "tab_loader.hpp"

#include <common/application.hpp>
#include <FL/Fl_Tabs.H>

#include <iostream>

void TabLoader::createTabs(Fl_Tabs& tabs, vector<IApplication*>& modules,
                           std::function<Fl_Group*(IApplication*)>&& getController) {
    for (auto*& module : modules) {
        auto* group = getController(module);
        if (group != nullptr) {
            std::cout << "Add view" << std::endl;
            tabs.add(group);
        }
    }
    tabs.end();
}

void TabLoader::clear(Fl_Tabs& tabs) {
    for (int i = 0; i < tabs.children(); i++) {
        tabs.remove(i);
    }
}