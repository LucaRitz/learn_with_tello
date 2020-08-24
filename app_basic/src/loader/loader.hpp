#pragma once

#include "library_loader.hpp"
#include <memory>

using std::unique_ptr;

unique_ptr<ILibraryLoader> getLoader();