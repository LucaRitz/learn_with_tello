#include "keyboard_view.hpp"

KeyboardView::KeyboardView() :
    Fl_Group(20, 55, 1280, 720, "Keyboard - Solution"),
    _aButton(25, 65, 100, 30, "Test Button"),
    _aBox(25, 105, 300, 200, "Label"),
    _listener(nullptr) {

    _aBox.box(FL_UP_BOX);
    _aBox.labelfont(FL_BOLD+FL_ITALIC);
    _aBox.labelsize(36);
    _aBox.labeltype(FL_SHADOW_LABEL);
    end();
}

void KeyboardView::setListener(IListener *listener) {
    _listener = listener;
}