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

MainView::MainView() : Fl_Window(0, 0, 1280, 990, "Learn with tello"),
    _listener(nullptr),
    _menuBar(0, 0, 1280, 30),
    _tabs(10, 40, 1280, 900) {
    resizable(_tabs);
    _menuBar.menu(popup);
    add(_menuBar);
    end();
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

Fl_Widget* MainView::activeView() {
    return _tabs.value();
}

void onSettingsPressed(Fl_Widget* widget, void* listener) {
    static_cast<mainview::IListener*>(listener)->onSettingsPressed();
}

void onTabChanged(Fl_Widget *widget, void* listener) {
    static_cast<mainview::IListener*>(listener)->onTabChanged();
}