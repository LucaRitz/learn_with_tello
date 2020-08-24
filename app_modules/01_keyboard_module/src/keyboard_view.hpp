#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class IListener {
public:
    virtual ~IListener() = default;
};

class KeyboardView : public Fl_Group {
public:
    explicit KeyboardView(IListener& listener);

private:
    IListener& _listener;
    Fl_Button _aButton;
    Fl_Box _aBox;
};