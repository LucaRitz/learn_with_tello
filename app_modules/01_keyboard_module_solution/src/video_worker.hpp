#pragma once

#include <common/worker.hpp>
#include <video/frame_grabber.hpp>

namespace tello {
    class Tello;
}

namespace cv {
    class Mat;
}

using tello::Tello;

class VideoWorkerListener {
public:
    virtual ~VideoWorkerListener() = default;
    virtual void picture(cv::Mat& picture) = 0;
};

class VideoWorker : public worker::Worker {
public:
    explicit VideoWorker(VideoWorkerListener& listener);

    void work() override;
    void activate() override;
    void deactivate() override;
    int delay() override;

    void tello(Tello* tello);

private:
    FrameGrabber _frameGrabber;
    VideoWorkerListener& _listener;
};