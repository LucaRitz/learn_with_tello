#include <common/frame_grabber.hpp>

#include <tello/tello.hpp>

#include "opencv2/opencv.hpp"

extern "C" {
#include <libavcodec/avcodec.h>
}

FrameGrabber::FrameGrabber() :
    _tello(nullptr),
    _grabFrame(),
    _frameMutex() {
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

#include <iostream>

void FrameGrabber::activate() {
    _tello->setVideoHandler([this](const VideoResponse& response) {
        _frameMutex.lock();
        if (_grabFrame != nullptr) {
            _decoder.parse(response.videoFrame(), response.length());
            _decoder.parse(response.videoFrame() + response.length(), 0); // Signal end of file

            if (_decoder.is_frame_available()) {
                try {
                    const AVFrame& frame = _decoder.decode_frame();

                    if (frame.key_frame) {
                        cv::Size actual_size(1024, 720);
                        cv::Size half_size(512, 360);

                        cv::Mat y(actual_size, CV_8UC1, frame.data[0]);
                        cv::Mat u(half_size, CV_8UC1, frame.data[1]);
                        cv::Mat v(half_size, CV_8UC1, frame.data[2]);

                        cv::Mat u_resized, v_resized;
                        cv::resize(u, u_resized, actual_size, 0, 0, cv::INTER_NEAREST); //repeat u values 4 times
                        cv::resize(v, v_resized, actual_size, 0, 0, cv::INTER_NEAREST); //repeat v values 4 times

                        cv::Mat yuv;

                        std::vector<cv::Mat> yuv_channels = { y, u_resized, v_resized };
                        cv::merge(yuv_channels, yuv);

                        cv::Mat bgr;
                        cv::cvtColor(yuv, bgr, cv::COLOR_YUV2BGR);

                        _grabFrame->_prom->set_value(bgr);
                        delete _grabFrame;
                        _grabFrame = nullptr;
                    }
                } catch(...) {
                    std::cout << "Exception occured" << std::endl;
                }
            }
        }
        _frameMutex.unlock();
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