#include <common/frame_grabber.hpp>

#include <tello/tello.hpp>

#include "opencv2/opencv.hpp"

extern "C" {
#include <libavcodec/avcodec.h>
}

FrameGrabber::FrameGrabber() :
    _tello(nullptr),
    _grabFrame(),
    _frameMutex(),
    _decoder(),
    _converter() {
    disable_logging();
}

future<cv::Mat> FrameGrabber::grabNext() {
    promise<Mat> prom{};
    future<Mat> fut_prom = std::move(prom.get_future());

    _frameMutex.lock();
    if (_grabFrame != nullptr) {
        _grabFrame->_prom->set_value(Mat{});
        delete _grabFrame;
    }
    _grabFrame = new FrameInfo{std::make_shared<promise < Mat>>(std::move(prom))};
    _frameMutex.unlock();

    return fut_prom;
}

void FrameGrabber::tello(Tello* tello) {
    this->_tello = tello;
}

void FrameGrabber::activate() {
    _tello->setVideoHandler([this](const VideoResponse& response) {
        _decoder.parse(response.videoFrame(), response.length());
        if (_decoder.is_frame_available()) {
            try {
                const auto& frame = _decoder.decode_frame();
                int bufferSize = _converter.predict_size(frame.width, frame.height);

                _frameMutex.lock();
                if (_grabFrame != nullptr) {
                    auto* buffer = new unsigned char[bufferSize];
                    auto& convertedFrame = _converter.convert(frame, buffer);

                    cv::Mat image{convertedFrame.height, convertedFrame.width, CV_8UC3, buffer,
                                  (size_t) convertedFrame.linesize[0]};

                    _grabFrame->_prom->set_value(image);
                    delete _grabFrame;
                    _grabFrame = nullptr;
                }
                _frameMutex.unlock();
            } catch (...) {
                // NOOP
            }
        }
    });

    auto video_resp = _tello->streamon();
    video_resp.wait();
}

void FrameGrabber::deactivate() {
    if (_tello) {
        auto video_off_resp = _tello->streamoff();
        video_off_resp.wait();
        _tello->setVideoHandler(nullptr);
    }
}