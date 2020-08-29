include(FetchContent)

set(OPTION_BUILD_SHARED_LIBS ON CACHE INTERNAL "")  # Forces the value
FetchContent_Declare(
        tello
        GIT_REPOSITORY https://github.com/LucaRitz/tello.git
        GIT_TAG        origin/shared-build
)

FetchContent_MakeAvailable(tello)
unset(OPTION_BUILD_SHARED_LIBS)