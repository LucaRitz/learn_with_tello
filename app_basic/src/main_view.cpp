#include "main_view.hpp"

#include <common/application.hpp>
#include "loader/tab_loader.hpp"

Fl_Menu_Item popup[] = {
        {"&File",	0,   nullptr, nullptr, FL_SUBMENU},
        {"Settings"},
        {nullptr}};

enum class MenuItemIndex {
    FILE,
    SETTINGS
};

void onSettingsPressed(Fl_Widget* widget, void* listener);
void onTabChanged(Fl_Widget *widget, void* listener);

MainView::MainView() : Fl_Group(20, 30, 1280, 720),
    _listener(nullptr),
    _window(1280, 720),
    _tabs(10, 40, 1280, 720),
    _menuBar(0, 0, 1280, 30) {
    _window.resizable(_tabs);
    _window.end();
    _window.label("Learn with tello");

    _menuBar.menu(popup);
    _window.add(_menuBar);
}

MainView::~MainView() {
    TabLoader::clear(_tabs);
}

void MainView::setModules(vector<IApplication*>& modules) {
    _tabs.clear();
    TabLoader::createTabs(_tabs, modules, [](auto* appli) { return appli->controller() != nullptr ? appli->controller()->view() : nullptr; });
}

void MainView::setListener(mainview::IListener* listener) {
    this->_listener = listener;
    popup[static_cast<int>(MenuItemIndex::SETTINGS)].callback(onSettingsPressed, _listener);
    _tabs.callback(onTabChanged, _listener);
}

void MainView::show(int argc, char **argv) {
    _window.show(argc, argv);
}

Fl_Widget* MainView::activeView() {
    return _tabs.value();
}

void onSettingsPressed(Fl_Widget* widget, void* listener) {
    static_cast<mainview::IListener*>(listener)->onSettingsPressed();
}

void onTabChanged(Fl_Widget *widget, void* listener) {
    static_cast<mainview::IListener*>(listener)->onTabChanged();
}