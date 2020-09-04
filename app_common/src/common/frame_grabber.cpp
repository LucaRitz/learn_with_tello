#include <common/frame_grabber.hpp>

#include <Decoder.h>
#include <tello/tello.hpp>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

FrameGrabber::FrameGrabber() :
    _tello(nullptr),
    _grabFrame(),
    _frameMutex() {
}

optional<future<cv::Mat>> FrameGrabber::grabNext() {
    promise<Mat> prom{};
    future<Mat> fut_prom = std::move(prom.get_future());

    _frameMutex.lock();
    _grabFrame = new FrameInfo{std::make_shared<promise < Mat>>(std::move(prom))};
    _frameMutex.unlock();

    return std::make_optional<future<Mat>>(std::move(fut_prom));
}

void FrameGrabber::tello(Tello* tello) {
    this->_tello = tello;
}

#include <iostream>

void FrameGrabber::activate() {
    auto video_resp = _tello->streamon();
    video_resp.wait();

    _tello->setVideoHandler([this](const VideoResponse& response) {
        _frameMutex.lock();
        if (_grabFrame != nullptr) {

            Stream s;

            s.SetStream(response.videoFrame(), response.length());
            u32 height, width;
            u8* img_data = nullptr;
            StreamStatus ret = s.BroadwayDecode();
            switch (ret) {
                case PIC_READY:
                    std::cout << "Get frame" << std::endl;
                    img_data = s.GetFrame(&width, &height);
                    break;

                case STREAM_ERROR:
                    std::cout << "Stream error" << std::endl;
                    break;
                case STREAM_ENDED:
                    std::cout << "Stream ended" << std::endl;
                    //streaming = false;
                    break;

                default:
                    break;
            }

            if (ret == PIC_READY) {
                std::cout << "Image ready" << std::endl;
                if(img_data == nullptr) {
                    std::cout << "Image data is NULL" << std::endl;
                    //break;
                }
                cv::Mat img_buffer(height+height/2, width, CV_8UC1, (uchar *)img_data);
                // if you want only grayscale you can directly get only Y. And if you want the
                // cr and cb channels separated, here you go
                // cv::Mat Y(height, width, CV_8UC1, (uchar *)img_data);
                // cv::Mat cb(height/2, width/2, CV_8UC1, (uchar *)(img_data+height*width));
                // cv::Mat cr(height/2, width/2, CV_8UC1, (uchar *)(img_data+height*width+(height/2)*(width/2)));
                cv::Mat original;
                cv::cvtColor(img_buffer, original, cv::COLOR_YUV2RGB_YV12);
                _grabFrame->_prom->set_value(original);
            } else {
                std::cout << "EMPTY" << std::endl;
                _grabFrame->_prom->set_value(cv::Mat{});
            }

            delete _grabFrame;
            _grabFrame = nullptr;
        }
        _frameMutex.unlock();
    });
}

void FrameGrabber::deactivate() {
    if (_tello) {
        auto video_off_resp = _tello->streamoff();
        video_off_resp.wait();
        _tello->setVideoHandler(nullptr);
    }
}