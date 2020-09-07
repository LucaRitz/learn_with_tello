#include "template_settings.hpp"

TemplateSettings::TemplateSettings() :
    _aValue(0) {
}

int TemplateSettings::aValue() {
    return _aValue;
}

void TemplateSettings::aValue(int aValue) {
    _aValue = aValue;
}