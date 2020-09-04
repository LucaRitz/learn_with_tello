#pragma once

#include <vector>
#include <tello/tello.hpp>
#include "settings.hpp"

using tello::Tello;
using std::vector;

class BaseSettings : public ISettings {
public:
    void setTellos(vector<Tello*> tellos);
    [[nodiscard]] vector<Tello*>& tellos();
    [[nodiscard]] const vector<Tello*>& tellos() const;

private:
    vector<Tello*> _tellos;
};