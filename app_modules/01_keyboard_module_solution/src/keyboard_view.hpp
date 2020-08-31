#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class IListener {

};

class KeyboardView : public Fl_Group {
public:
    KeyboardView();

    void setListener(IListener* listener);
private:
    Fl_Button _aButton;
    Fl_Box _aBox;
    IListener* _listener;
};