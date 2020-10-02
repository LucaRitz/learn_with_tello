#include "windows_library_loader.hpp"
#include <filesystem>

namespace fs = std::filesystem;
typedef IApplication* (__cdecl *ModuleLoader)();

vector<IApplication*> WindowsLibraryLoader::load(string path) {
    vector<IApplication*> modules;

    for (const auto& entry : fs::directory_iterator(path)) {
        string file = entry.path().string();
        if (file.find(".dll") == std::string::npos) {
            continue;
        }

        HINSTANCE libInstance = LoadLibrary(TEXT(file.c_str()));
        if (libInstance != nullptr) {
            _dlls.push_back(libInstance);
            auto loaderAddress = (ModuleLoader) GetProcAddress(libInstance, "loadModule");

            if (loaderAddress != nullptr) {
                auto* appli = (loaderAddress)();
                modules.emplace_back(appli);
            }
        }
    }

    return modules;
}

WindowsLibraryLoader::~WindowsLibraryLoader() {
    for(auto& dll : _dlls) {
        FreeLibrary(dll);
    }
    _dlls.clear();
}