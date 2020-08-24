include(FetchContent)
FetchContent_Declare(
        tello
        GIT_REPOSITORY https://github.com/LucaRitz/tello.git
        GIT_TAG        1.0.0
)
FetchContent_MakeAvailable(tello)