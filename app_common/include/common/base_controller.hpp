#pragma once

class Fl_Group;

class BaseController {
public:
    virtual ~BaseController() = default;

    virtual void activate() = 0;
    virtual void deactivate() = 0;

    virtual Fl_Group* view() = 0;
};