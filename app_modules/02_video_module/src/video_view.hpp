#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

class IListener {
public:
    virtual void takePicture() = 0;
};

class VideoView : public Fl_Group {
public:
    VideoView();

    void setListener(IListener* listener);
private:
    Fl_Button _takePictureBtn;
    IListener* _listener;
};