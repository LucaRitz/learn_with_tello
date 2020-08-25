#pragma once

#include "main_view.hpp"

class MainController : public IListener {
public:
    explicit MainController(MainView* view);

    void onSettingsPressed() const override;

    void setModules(vector<IApplication*>& modules);
    void show(int argc, char **argv);

private:
    MainView* _view;
};