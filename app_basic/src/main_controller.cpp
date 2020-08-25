#include "main_controller.hpp"

#include <iostream>

MainController::MainController(MainView* view) :
    _view(view) {
    _view->setListener(this);
}

void MainController::onSettingsPressed() const {
    std::cout << "On settings pressed" << std::endl;
}

void MainController::setModules(vector<IApplication*>& modules) {
    _view->setModules(modules);
}

void MainController::show(int argc, char **argv) {
    _view->show(argc, argv);
}

