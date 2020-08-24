#pragma once

#include "keyboard_view.hpp"

class Application;

class KeyboardController : public IListener {
public:
    explicit KeyboardController(Application* module);
    ~KeyboardController() override = default;

private:
    Application* _module;
};