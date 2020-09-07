#include "view.hpp"

#include <FL/Fl.H>

static void onActionPressed(Fl_Widget* widget, void* listener);

View::View() :
        Fl_Group(20, 55, 1280, 720, "Template"),
        _actionBtn(25, 65, 100, 30, "Action"),
        _listener(nullptr) {
    end();
}

void View::setListener(IListener *listener) {
    _listener = listener;
    _actionBtn.callback(onActionPressed, listener);
}

void onActionPressed(Fl_Widget* widget, void* listener) {
    static_cast<IListener*>(listener)->onViewAction();
}