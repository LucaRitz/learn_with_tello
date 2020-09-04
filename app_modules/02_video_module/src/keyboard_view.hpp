#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

class IListener {

};

class KeyboardView : public Fl_Group {
public:
    KeyboardView();

    void setListener(IListener* listener);
private:
    Fl_Button _takeOffButton;
    IListener* _listener;
};