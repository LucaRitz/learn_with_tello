#include "keyboard_view.hpp"

KeyboardView::KeyboardView() :
        Fl_Group(20, 55, 1280, 720, "Video"),
        _takeOffButton(25, 65, 100, 30, "Test Button"),
        _listener(nullptr) {
    end();
}

void KeyboardView::setListener(IListener *listener) {
    _listener = listener;
}