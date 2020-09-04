#pragma once

#include <common/keyboard_settings.hpp>

namespace mathematical {
    class LinearFunction : public Function {
    public:
        [[nodiscard]] int calc(int min, int max, int time) const override;
    };
}