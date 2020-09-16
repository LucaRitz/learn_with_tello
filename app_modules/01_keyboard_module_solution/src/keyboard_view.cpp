#include "keyboard_view.hpp"

#include <FL/Fl.H>

static void takeOffButtonPressed(Fl_Widget* widget, void* listener);

KeyboardView::KeyboardView() :
        Fl_Group(20, 55, 1280, 900, "Keyboard - Solution"),
        _takeOffButton(25, 65, 100, 30, "Take off or land"),
        _videoWidget(200, 65, 960, 720),
        _listener(nullptr) {
    _videoWidget.resizable(_videoWidget);
    end();
}

void KeyboardView::setListener(IListener *listener) {
    _listener = listener;
    _takeOffButton.callback(takeOffButtonPressed, listener);
}

#include <iostream>

int KeyboardView::handle(int event) {
    _pressedKeys.clear();
    int pressedKey = Fl::event_key();
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

void KeyboardView::picture(cv::Mat& picture) {
    _videoWidget.frame(picture);
}

void takeOffButtonPressed(Fl_Widget* widget, void* listener) {
    static_cast<IListener*>(listener)->takeOffOrLand();
}