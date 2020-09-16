#pragma once

#include <common/base_controller.hpp>
#include <common/worker.hpp>

#include "keyboard_view.hpp"
#include "command_thread.hpp"
#include "command_worker.hpp"
#include "video_worker.hpp"
#include "takeoff_worker.hpp"

class Application;

class KeyboardController : public IListener, public VideoWorkerListener, public BaseController {
public:
    KeyboardController(KeyboardView* view, Application* module);

    void activate() override;
    void deactivate() override;

    void keyPressed(const vector<command::Key>& pressedKeys) override;
    void takeOffOrLand() override;

    void picture(cv::Mat& picture) override;

    Fl_Group* view() override;

private:
    KeyboardView* _view;
    Application* _module;
    worker::WorkExecutor _workUiExecutor;
    worker::WorkExecutor _workExecutor;
    CommandWorker _commandWorker;
    VideoWorker _videoWorker;
    bool _isFlying;
    TakeoffWorker _takeoffWorker;
};