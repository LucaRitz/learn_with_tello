#pragma once

#include <common/base_controller.hpp>

#include "keyboard_view.hpp"
#include "command_thread.hpp"

class Application;

class KeyboardController : public IListener, public BaseController {
public:
    KeyboardController(KeyboardView* view, Application* module);

    void activate() override;
    void deactivate() override;

    void keyPressed(const vector<command::Key>& pressedKeys) override;
    void takeOffOrLand() override;

    Fl_Group* view() override;

private:
    KeyboardView* _view;
    Application* _module;
    CommandThread _commandThread;
    bool _isFlying;
};