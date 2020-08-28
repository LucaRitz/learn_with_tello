#pragma once

#include "keyboard_view.hpp"

class Application;

class KeyboardController : public IListener {
public:
    KeyboardController(KeyboardView* view, Application* module);

private:
    KeyboardView* _view;
    Application* _module;
};