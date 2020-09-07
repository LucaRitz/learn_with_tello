#include "controller.hpp"

#include "application.hpp"

#include <iostream>

Controller::Controller(View* view, Application* module) :
    _view(view),
    _module(module) {
    _view->setListener(this);
}

void Controller::activate() {
    std::cout << "Controller::activate" << std::endl;
}

void Controller::deactivate() {
    std::cout << "Controller::deactivate" << std::endl;
}

void Controller::onViewAction() {
    std::cout << "Controller::onViewAction" << std::endl;
}

Fl_Group* Controller::view() {
    return _view;
}