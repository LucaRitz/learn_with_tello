#include "keyboard_view.hpp"

#include <FL/Fl.H>

static void takeOffButtonPressed(Fl_Widget* widget, void* listener);

KeyboardView::KeyboardView() :
        Fl_Group(20, 55, 1280, 720, "Keyboard - Solution"),
        _takeOffButton(25, 65, 100, 30, "Take off or land"),
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
    _takeOffButton.callback(takeOffButtonPressed, listener);
}

#include <iostream>

int KeyboardView::handle(int event) {
    std::cout << "handle event" << std::endl;
    _pressedKeys.clear();
    //int pressedKey = Fl::event_key();
    switch (event) {
        case FL_KEYDOWN:
            std::cout << "Key up" << std::endl;
            _pressedKeys.push_back(command::Key::FORWARD);
            break;
        default:
            break;
    }
    _listener->keyPressed(_pressedKeys);
    return Fl_Group::handle(event);
}

void takeOffButtonPressed(Fl_Widget* widget, void* listener) {
    static_cast<IListener*>(listener)->takeOffOrLand();
}