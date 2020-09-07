#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Int_Input.H>
#include <memory>

class TemplateSettings;

class SettingsView : public Fl_Group {
public:
    SettingsView();

    void show(std::shared_ptr<TemplateSettings>& settings);
    void save(std::shared_ptr<TemplateSettings>& settings) const;

private:
    Fl_Int_Input _valueInput;
};