#pragma once

#include <common/settings.hpp>

class TemplateSettings : public ISettings {
public:
    TemplateSettings();

    void aValue(int aValue);
    int aValue();

private:
    int _aValue;
};