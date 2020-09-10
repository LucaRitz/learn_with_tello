#include <video/frame_grabber.hpp>

#include "frame_grabber_internal.hpp"
#include "opencv2/opencv.hpp"

FrameGrabber::FrameGrabber() :
    _ptr(std::make_unique<FrameGrabberInternal>()) {
}

FrameGrabber::~FrameGrabber() = default;

future<cv::Mat> FrameGrabber::grabNext() {
    return _ptr->grabNext();
}

void FrameGrabber::tello(Tello* tello) {
    _ptr->tello(tello);
}

void FrameGrabber::activate() {
    _ptr->activate();
}

void FrameGrabber::deactivate() {
    _ptr->deactivate();
}