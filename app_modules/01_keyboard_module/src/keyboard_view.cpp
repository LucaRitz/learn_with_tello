#include "keyboard_view.hpp"

KeyboardView::KeyboardView(IListener& listener) :
    Fl_Group(20, 30, 1280, 720, "Keyboard"),
    _listener(listener),
    _aButton(25, 35, 100, 30, "Test Button"),
    _aBox(25, 75, 300, 200, "Label") {

    _aBox.box(FL_UP_BOX);
    _aBox.labelfont(FL_BOLD+FL_ITALIC);
    _aBox.labelsize(36);
    _aBox.labeltype(FL_SHADOW_LABEL);
    end();
}
