#pragma once

class Fl_Group;
class ISettings;

class ISettingsController {
public:
    ~ISettingsController() = default;

    [[nodiscard]] virtual Fl_Group* getView() = 0;
    virtual ISettings* save() = 0;
    virtual void updateView() = 0;
};