#pragma once

#include "common/settings.hpp"
#include "../functions/linear_function.hpp"
#include "../types.hpp"

class KeyboardSettings : public ISettings {
public:
    KeyboardSettings();

    void function(mathematical::Function* function);
    mathematical::Function* function();

    mathematical::LinearFunction linearFunction();

private:
    mathematical::LinearFunction _linearFunction;

    mathematical::Function* _function;
};