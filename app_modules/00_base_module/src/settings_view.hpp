#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Int_Input.H>
#include <memory>

class BaseSettings;

class SettingsView : public Fl_Group {
public:
    SettingsView();

    void show(std::shared_ptr<BaseSettings>& settings);
    void save(std::shared_ptr<BaseSettings>& settings) const;

private:
    Fl_Int_Input _telloIpInput;
};