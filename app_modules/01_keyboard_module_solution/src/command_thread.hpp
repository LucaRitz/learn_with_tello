#pragma once

#include <vector>
#include <shared_mutex>
#include <thread>
#include <future>
#include <unordered_map>
#include <chrono>
#include <atomic>

#include "types.hpp"

namespace tello {
    class Tello;
}

namespace mathematical {
    class Function;
}

using std::promise;
using std::shared_mutex;
using std::thread;
using std::vector;
using std::future;
using std::unordered_map;
using tello::Tello;
using std::atomic_bool;

class CommandThread {
public:
    CommandThread();
    ~CommandThread();

    void pause();
    void play();
    void tello(Tello* tello);
    void mappingFunction(const mathematical::Function* mappingFunction);

    void activeKeys(const vector<command::Key>& keys);

private:
    atomic_bool _running;
    promise<void> _exitSignal;
    shared_mutex _activeKeyMutex;
    vector<command::Key> _activeKeys;
    Tello* _tello;
    const mathematical::Function* _mappingFunction;
    thread _worker;

    void listen(shared_mutex& activeKeyMutex, atomic_bool& running, future<void> exitListener,
            vector<command::Key>& activeKeys, Tello*& tello, const mathematical::Function*& mappingFunction);

    void fly(Tello*& tello, const mathematical::Function*& mappingFunction,
             const unordered_map<command::Key, std::chrono::duration<double>>& durationKeyMap);

    [[nodiscard]] unordered_map<command::Key, std::chrono::duration<double>>
    buildDurationKeyMap(
            const unordered_map<command::Key, std::chrono::duration<double>>& currentDurationKeyMap,
            const vector<command::Key>& activeKeys,
            const std::chrono::duration<double>& difference) const;
};