#pragma once

#include <common/base_controller.hpp>

#include "keyboard_view.hpp"

class Application;

class KeyboardController : public IListener, public BaseController {
public:
    KeyboardController(KeyboardView* view, Application* module);

    void activate() override;
    void deactivate() override;

    Fl_Group* view() override;

private:
    KeyboardView* _view;
    Application* _module;
};