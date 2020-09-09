#include "keyboard_settings.hpp"

KeyboardSettings::KeyboardSettings() :
    _linearFunction(),
    _function(&_linearFunction) {

}

void KeyboardSettings::function(mathematical::Function *function) {
    _function = function;
}

mathematical::Function * KeyboardSettings::function() {
    return _function;
}

mathematical::LinearFunction KeyboardSettings::linearFunction() {
    return _linearFunction;
}