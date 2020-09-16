#pragma once

#include <common/worker.hpp>

class Application;

class TakeoffWorker : public worker::Worker {
public:
    TakeoffWorker(Application* module, bool& isFlying);

    void work() override;

private:
    bool& _isFlying;
    Application* _module;
};