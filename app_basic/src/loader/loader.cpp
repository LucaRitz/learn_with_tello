#include "loader.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)

    #include "windows/windows_library_loader.hpp"
    unique_ptr<ILibraryLoader> getLoader() {
        return std::make_unique<WindowsLibraryLoader>();
    }

#endif