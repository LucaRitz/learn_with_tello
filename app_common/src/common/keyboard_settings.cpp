#include <common/keyboard_settings.hpp>

void KeyboardSettings::function(mathematical::Function *function) {
    _function = function;
}

mathematical::Function * KeyboardSettings::function() {
    return _function;
}