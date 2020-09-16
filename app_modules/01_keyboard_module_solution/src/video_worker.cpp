#include "video_worker.hpp"

#include <opencv2/core.hpp>

VideoWorker::VideoWorker(VideoWorkerListener& listener) :
    _listener(listener) {
}

void VideoWorker::work() {
    future<cv::Mat> frame = _frameGrabber.grabNext();
    frame.wait();
    _listener.picture(frame.get());
}

void VideoWorker::activate() {
    _frameGrabber.activate();
}

void VideoWorker::deactivate() {
    _frameGrabber.deactivate();
}

int VideoWorker::delay() {
    return 0;
}

void VideoWorker::tello(Tello* tello) {
    _frameGrabber.tello(tello);
}