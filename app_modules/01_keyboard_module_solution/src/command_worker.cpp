#include "command_worker.hpp"

#include <tello/tello.hpp>
#include <iostream>

void CommandWorker::work() {
    static auto lastRunTime = std::chrono::system_clock::now();

    _keyMutex.lock();
    auto currentTime = std::chrono::system_clock::now();
    if (_tello != nullptr) {
        std::chrono::duration<double> difference = currentTime - lastRunTime;
        _timeInSecondsByKeys = buildDurationKeyMap(_timeInSecondsByKeys, _activeKeys, difference);

        fly(_tello, _mappingFunction, _timeInSecondsByKeys);
    }
    lastRunTime = currentTime;
    _keyMutex.unlock();
}

void CommandWorker::activate() {
    // NOOP
}

void CommandWorker::deactivate() {
    _timeInSecondsByKeys.clear();
}

void CommandWorker::tello(Tello* tello) {
    _tello = tello;
}

void CommandWorker::mappingFunction(const mathematical::Function* mappingFunction) {
    _mappingFunction = mappingFunction;
}

void CommandWorker::activeKeys(const vector<command::Key> &keys) {
    _keyMutex.lock();
    _activeKeys.clear();
    _activeKeys.insert(_activeKeys.end(), keys.begin(), keys.end());
    _keyMutex.unlock();
}

void
CommandWorker::fly(Tello*& tello, const mathematical::Function*& mappingFunction,
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
    tello->rc_control(x, y, z, r);
}

unordered_map<command::Key, std::chrono::duration<double>> CommandWorker::buildDurationKeyMap(
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