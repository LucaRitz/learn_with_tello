#include <FL/Fl.H>

#include "loader/loader.hpp"
#include "main_controller.hpp"
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

    Fl::lock();

    MainView mainView;
    MainController mainController {&mainView, modules};

    int returnCode = Fl::run();

    for(auto& module : modules) {
        module->tearDown();
    }

    return returnCode;
}