#include "view.hpp"

#include <FL/Fl.H>

static void onActionPressed(Fl_Widget* widget, void* listener);

View::View() :
        Fl_Group(0, 80, 500, 900, "Template"),
        _actionBtn(25, 100, 100, 30, "Action"),
        _listener(nullptr) {
    add(_actionBtn);
    end();
}

void View::setListener(IListener *listener) {
    _listener = listener;
    _actionBtn.callback(onActionPressed, listener);
}

void onActionPressed(Fl_Widget* widget, void* listener) {
    static_cast<IListener*>(listener)->onViewAction();
}