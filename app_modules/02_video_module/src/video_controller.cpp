#include "video_controller.hpp"

#include "application.hpp"
#include <opencv2/highgui.hpp>

VideoController::VideoController(VideoView* view, Application* module) :
    _view(view),
    _module(module),
    _frameGrabber() {
    _view->setListener(this);
}

void VideoController::activate() {
    auto com_resp = _module->baseSettings()->tellos().at(0)->command();
    com_resp.wait();
    _frameGrabber.tello(_module->baseSettings()->tellos().at(0));
}

void VideoController::deactivate() {
    _frameGrabber.deactivate();
}

void VideoController::takePicture() {
    _frameGrabber.activate();

    while(true) {
        auto image = _frameGrabber.grabNext();
        Mat matIm = image.get();
        cv::imshow("Image", matIm);
        int key = cv::waitKey(1);
        if (27 /* ESC */ == key) {
            break;
        }
    }
}

Fl_Group* VideoController::view() {
    return _view;
}