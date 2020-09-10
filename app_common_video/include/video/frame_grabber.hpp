#pragma once

#include <future>
#include <memory>
#include <common/macro_definition.hpp>

namespace tello {
    class Tello;
}

namespace cv {
    class Mat;
}

class FrameGrabberInternal;

using tello::Tello;
using std::mutex;
using std::future;
using std::shared_ptr;
using cv::Mat;
using std::promise;

class EXPORT FrameGrabber {
public:
    FrameGrabber();
    ~FrameGrabber();

    future<Mat> grabNext();

    void tello(Tello* tello);
    void activate();
    void deactivate();

private:
    std::unique_ptr<FrameGrabberInternal> _ptr;
};