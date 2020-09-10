#pragma once

#include <common/base_controller.hpp>
#include <video/frame_grabber.hpp>

#include "video_view.hpp"

class Application;

class VideoController : public IListener, public BaseController {
public:
    VideoController(VideoView* view, Application* module);

    void activate() override;
    void deactivate() override;
    void takePicture() override;

    Fl_Group* view() override;

private:
    VideoView* _view;
    Application* _module;
    FrameGrabber _frameGrabber;
};