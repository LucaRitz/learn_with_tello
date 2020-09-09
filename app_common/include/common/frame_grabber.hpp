#pragma once

#include <mutex>
#include <optional>
#include <future>
#include <memory>
#include "H264Decoder.hpp"

namespace tello {
    class Tello;
}

namespace cv {
    class Mat;
}

using tello::Tello;
using std::mutex;
using std::future;
using std::shared_ptr;
using cv::Mat;
using std::promise;

struct FrameInfo {
    shared_ptr<promise<Mat>> _prom;
};

class FrameGrabber {
public:
    FrameGrabber();

    future<Mat> grabNext();

    void tello(Tello* tello);
    void activate();
    void deactivate();

private:
    Tello* _tello;
    FrameInfo* _grabFrame;
    mutex _frameMutex;
    H264Decoder _decoder;
    ConverterRGB24 _converter;
};