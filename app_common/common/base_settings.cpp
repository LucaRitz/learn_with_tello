#include "base_settings.hpp"

void BaseSettings::setTellos(vector<Tello*> tellos) {
    _tellos = std::move(tellos);
}

vector<Tello*> BaseSettings::tellos() const {
    return _tellos;
}