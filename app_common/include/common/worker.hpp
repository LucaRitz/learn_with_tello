#pragma once

#include <vector>
#include <mutex>
#include <thread>
#include <future>
#include <atomic>

using std::mutex;
using std::thread;
using std::vector;
using std::promise;
using std::atomic_bool;
using std::future;

namespace worker {
    class WorkExecutor;

    class Worker {
    public:
        Worker();
        ~Worker() = default;
        virtual void work() = 0;
        virtual void activate();
        virtual void deactivate();
        virtual int delay();

        bool attached();

        friend class WorkExecutor;

    private:
        bool _attached;
    };

    struct WorkerData {
        Worker* _worker;
        int _waitCount = 0;
        bool _executeOnce = false;
    };

    class WorkExecutor {
    public:
        WorkExecutor();
        ~WorkExecutor();

        void append(Worker& worker, bool executeOnce = false);
        void pause();
        void play();

    private:
        vector<WorkerData> _workers;
        atomic_bool _running;
        promise<void> _exitSignal;
        mutex _mutex;
        thread _worker;

        void listen(mutex& mutex, atomic_bool& running, future<void> exitListener,
                    vector<WorkerData>& workers);
    };
}