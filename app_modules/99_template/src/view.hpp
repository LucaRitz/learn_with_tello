#pragma once

#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

class IListener {
public:
   virtual void onViewAction() = 0;
};

class View : public Fl_Group {
public:
    View();

    void setListener(IListener* listener);

private:
    Fl_Button _actionBtn;
    IListener* _listener;
};