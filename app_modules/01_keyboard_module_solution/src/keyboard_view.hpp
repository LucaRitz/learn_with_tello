#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <video/opencv_widget.hpp>

#include "types.hpp"

class IListener {
public:
    virtual void keyPressed(const vector<command::Key>& pressedKeys) = 0;
    virtual void takeOffOrLand() = 0;
};

class KeyboardView : public Fl_Group {
public:
    KeyboardView();

    void setListener(IListener* listener);
    int handle(int event) override;

    void picture(cv::Mat& picture);

private:
    Fl_Button _takeOffButton;
    OpencvWidget _videoWidget;
    IListener* _listener;
    vector<command::Key> _pressedKeys;
};