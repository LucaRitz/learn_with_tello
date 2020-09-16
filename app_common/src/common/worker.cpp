#include <common/worker.hpp>

worker::Worker::Worker() : _attached(false) {

}

void worker::Worker::activate() {
    // NOOP
}

void worker::Worker::deactivate() {
    // NOOP
}

int worker::Worker::delay() {
    return 0;
}

bool worker::Worker::attached() {
    return _attached;
}

worker::WorkExecutor::WorkExecutor() :
        _workers(),
        _running(false),
        _exitSignal(),
        _mutex(),
        _worker(thread(&WorkExecutor::listen, this, std::ref(_mutex), std::ref(_running),
                       _exitSignal.get_future(), std::ref(_workers))) {

}

worker::WorkExecutor::~WorkExecutor() {
    pause();
    _exitSignal.set_value();
    _worker.join();
}

void worker::WorkExecutor::append(Worker& worker, bool executeOnce) {
    bool startAfter = _running;
    _running = false;
    _mutex.lock();
    WorkerData workerData {&worker, 0, executeOnce};
    _workers.push_back(workerData);
    worker._attached = true;
    _mutex.unlock();
    _running = startAfter;
}

#include <iostream>
void worker::WorkExecutor::pause() {
    _running = false;
    _mutex.lock();
    for(auto& worker : _workers) {
        worker._waitCount = 0;
        worker._worker->deactivate();
    }
    _mutex.unlock();
}

void worker::WorkExecutor::play() {
    _mutex.lock();
    for(auto& worker : _workers) {
        worker._worker->activate();
    }
    _mutex.unlock();
    _running = true;
}

void worker::WorkExecutor::listen(mutex& mutex, atomic_bool& running, future<void> exitListener,
                                  vector<WorkerData>& workers) {
    while (exitListener.wait_for(std::chrono::milliseconds(10)) == std::future_status::timeout) {
        if (running) {
            _mutex.lock();
            auto worker = workers.begin();
            while(worker != workers.end()) {
                if (worker->_waitCount == 0) {
                    worker->_worker->work();

                    if (worker->_executeOnce) {
                        worker->_worker->_attached = false;
                        worker = workers.erase(worker);
                        continue;
                    } else {
                        worker->_waitCount = worker->_worker->delay();
                    }
                } else {
                    worker->_waitCount--;
                }
                worker++;
            }
            _mutex.unlock();
        }
    }
}