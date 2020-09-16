#include "takeoff_worker.hpp"

#include <tello/tello.hpp>
#include <tello/response.hpp>

#include "application.hpp"

TakeoffWorker::TakeoffWorker(Application* module, bool& isFlying) :
    _module(module),
    _isFlying(isFlying) {
}

void TakeoffWorker::work() {
    if (!_isFlying) {
        std::future<tello::Response> takeOffResponse = _module->baseSettings()->tellos().at(0)->takeoff();
        takeOffResponse.wait();
        _isFlying = tello::Status::OK == takeOffResponse.get().status();
    } else {
        std::future<tello::Response> landResponse = _module->baseSettings()->tellos().at(0)->land();
        landResponse.wait();
        _isFlying = tello::Status::OK != landResponse.get().status();
    }
}