#include "tab_loader.hpp"

#include <common/application.hpp>
#include <FL/Fl_Tabs.H>

void TabLoader::createTabs(Fl_Tabs& tabs, vector<IApplication*>& modules, std::function<Fl_Group*(IApplication*)>&& getView) {
    for(auto*& module : modules) {
        auto* group = getView(module);
        if (group != nullptr) {
            tabs.add(group);
        }
    }
    tabs.end();
}