#pragma once

#include <windows.h>
#include "../library_loader.hpp"

class WindowsLibraryLoader : public ILibraryLoader {
public:
    ~WindowsLibraryLoader();
    vector<IApplication*> load(string path) override;

private:
    vector<HINSTANCE> _dlls;
};