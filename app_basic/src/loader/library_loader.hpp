#pragma once

#include <vector>
#include <string>
#include <memory>
#include <common/application.hpp>

using std::vector;
using std::string;
using std::unique_ptr;

class ILibraryLoader {
public:
    virtual ~ILibraryLoader() = default;
    virtual vector<IApplication*> load(string path) = 0;
};