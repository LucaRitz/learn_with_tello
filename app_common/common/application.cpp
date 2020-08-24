#include "application.hpp"

void IApplication::addDependent(IApplication* dependent) {
    _dependentModules.push_back(dependent);
}