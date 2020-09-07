#pragma once

#include <common/base_controller.hpp>

#include "view.hpp"

class Application;

class Controller : public IListener, public BaseController {
public:
    Controller(View* view, Application* module);

    void activate() override;
    void deactivate() override;

    void onViewAction() override;

    Fl_Group* view() override;

private:
    View* _view;
    Application* _module;
};