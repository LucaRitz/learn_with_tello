#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Choice.H>
#include <memory>

class KeyboardSettings;

enum class FunctionType {
    LINEAR
};

namespace settings {
    class IListener {
    public:
        virtual ~IListener() = default;

        virtual void onFunctionChanged(const FunctionType& functionType) = 0;
    };
}

class SettingsView : public Fl_Group {
public:
    SettingsView();

    void show(std::shared_ptr<KeyboardSettings>& settings);
    void save(std::shared_ptr<KeyboardSettings>& settings) const;

    void setListener(settings::IListener* listener);

private:
    settings::IListener* _listener;
    Fl_Choice _functionChoice;
};