include(FetchContent)

set(TELLO_BUILD_SHARED_LIBS ON CACHE INTERNAL "")  # Forces the value
FetchContent_Declare(
        tello
        GIT_REPOSITORY https://github.com/LucaRitz/tello.git
        GIT_TAG        origin/mingw-w64-build
)

FetchContent_MakeAvailable(tello)
unset(TELLO_BUILD_SHARED_LIBS)