#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>

#include "loader/loader.hpp"
#include "loader/tab_loader.hpp"
#include <iostream>

int main(int argc, char **argv) {
    unique_ptr<ILibraryLoader> loader = getLoader();
    vector<IApplication*> modules = loader->load("./libs/");
    for(auto& module : modules) {
        int returnCode = module->init();
        if (returnCode != 0) {
            std::cerr << "Module " << (int) module->id() << " failed with code: " << returnCode << std::endl;
            return returnCode;
        }
    }

    auto* window = new Fl_Window(1280,720);
    auto* tabs = TabLoader::createTabs(modules);
    window->resizable(tabs);
    window->end();
    window->label("Learn with tello");
    window->show(argc, argv);

    int returnCode = Fl::run();

    for(auto& module : modules) {
        module->tearDown();
    }

    return returnCode;
}