#pragma once

#include <opencv2/core.hpp>
#include <mutex>
#include <optional>
#include <future>
#include <memory>

namespace tello {
    class Tello;
}

using tello::Tello;
using std::mutex;
using std::optional;
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

    optional<future<Mat>> grabNext();

    void tello(Tello* tello);
    void activate();
    void deactivate();

private:
    Tello* _tello;
    FrameInfo* _grabFrame;
    mutex _frameMutex;
};