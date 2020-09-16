#pragma once

#include <common/worker.hpp>
#include <chrono>
#include <unordered_map>

#include "types.hpp"

namespace tello {
    class Tello;
}

using tello::Tello;
using std::unordered_map;

class CommandWorker : public worker::Worker {
public:
    void work() override;
    void activate() override;
    void deactivate() override;

    void tello(Tello* tello);
    void mappingFunction(const mathematical::Function* mappingFunction);
    void activeKeys(const vector<command::Key>& keys);

private:
    mutex _keyMutex;
    vector<command::Key> _activeKeys;
    Tello* _tello;
    const mathematical::Function* _mappingFunction;
    unordered_map<command::Key, std::chrono::duration<double>> _timeInSecondsByKeys;

    void fly(Tello*& tello, const mathematical::Function*& mappingFunction,
             const unordered_map<command::Key, std::chrono::duration<double>>& durationKeyMap);

    [[nodiscard]] unordered_map<command::Key, std::chrono::duration<double>>
    buildDurationKeyMap(
            const unordered_map<command::Key, std::chrono::duration<double>>& currentDurationKeyMap,
            const vector<command::Key>& activeKeys,
            const std::chrono::duration<double>& difference) const;
};