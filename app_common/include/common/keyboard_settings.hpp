#pragma once

#include "settings.hpp"

namespace mathematical {
    class Function {
    public:
        [[nodiscard]] virtual int calc(int min, int max, int time) const = 0;
    };
}

class KeyboardSettings : public ISettings {
public:
    KeyboardSettings() = default;

    void function(mathematical::Function* function);
    mathematical::Function* function();

private:
    mathematical::Function* _function;
};