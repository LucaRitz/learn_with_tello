#include "command_thread.hpp"

#include <common/keyboard_settings.hpp>
#include <tello/tello.hpp>

CommandThread::CommandThread() :
        _running(false),
        _exitSignal(),
        _activeKeyMutex(),
        _activeKeys(),
        _tello(nullptr),
        _mappingFunction(nullptr),
        _worker(thread(&CommandThread::listen, this, std::ref(_activeKeyMutex), std::ref(_running),
                       _exitSignal.get_future(), std::ref(_activeKeys), std::ref(_tello), std::ref(_mappingFunction))) {
}

CommandThread::~CommandThread() {
    _exitSignal.set_value();
    _worker.join();
}

void CommandThread::pause() {
    _running = false;
}

void CommandThread::play() {
    _running = true;
}

void CommandThread::tello(Tello* tello) {
    _tello = tello;
}

void CommandThread::mappingFunction(const mathematical::Function* mappingFunction) {
    _mappingFunction = mappingFunction;
}

void CommandThread::activeKeys(const vector<command::Key> &keys) {
    _activeKeyMutex.lock();
    _activeKeys.clear();
    _activeKeys.insert(_activeKeys.end(), keys.begin(), keys.end());
    _activeKeyMutex.unlock();
}

void CommandThread::listen(shared_mutex& activeKeyMutex, atomic_bool& running, future<void> exitListener,
        vector<command::Key>& activeKeys, Tello*& tello, const mathematical::Function*& mappingFunction) {

    unordered_map<command::Key, std::chrono::duration<double>> timeInSecondsByKeys {};
    auto lastRunTime = std::chrono::system_clock::now();

    while (exitListener.wait_for(std::chrono::milliseconds (100)) == std::future_status::timeout) {
        auto currentTime = std::chrono::system_clock::now();
        if (tello != nullptr && running) {
            std::chrono::duration<double> difference = currentTime - lastRunTime;
            timeInSecondsByKeys = buildDurationKeyMap(timeInSecondsByKeys, activeKeys, difference);

            fly(tello, mappingFunction, timeInSecondsByKeys);
        } else {
            timeInSecondsByKeys.clear();
        }
        lastRunTime = currentTime;
    }
}

#include <iostream>
void
CommandThread::fly(Tello*& tello, const mathematical::Function*& mappingFunction,
                   const unordered_map<command::Key, std::chrono::duration<double>>& durationKeyMap) {
    int x = 0;
    int y = 0;
    int z = 0;
    int r = 0;
    for (auto it : durationKeyMap) {
        switch (it.first) {
            case command::Key::FORWARD:
                x = mappingFunction->calc(200, 200, static_cast<int>(it.second.count()));
                break;
        }
    }

    std::cout << "x: " << x << std::endl;
    tello->rc_control(x, y, z, r);
}

unordered_map<command::Key, std::chrono::duration<double>> CommandThread::buildDurationKeyMap(
        const unordered_map<command::Key, std::chrono::duration<double>>& currentDurationKeyMap,
        const vector<command::Key>& activeKeys,
        const std::chrono::duration<double>& difference) const {

    unordered_map<command::Key, std::chrono::duration<double>> durationKeyMap{};

    for (auto key : command::ALL_KEYS) {
        if (currentDurationKeyMap.find(key) != currentDurationKeyMap.end()) {
            auto it = currentDurationKeyMap.find(key);
            if (it != currentDurationKeyMap.end()) {
                durationKeyMap[it->first] = it->second + difference;
            } else {
                durationKeyMap[key] = std::chrono::duration<double>{0};
            }
        }
    }

    return durationKeyMap;
}
