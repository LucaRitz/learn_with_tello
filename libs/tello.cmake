include(FetchContent)

set(TELLO_BUILD_SHARED_LIBS ON CACHE INTERNAL "")  # Forces the value
FetchContent_Declare(
        tello
        GIT_REPOSITORY https://github.com/LucaRitz/tello.git
        GIT_TAG        1.0.2
)

FetchContent_MakeAvailable(tello)
unset(TELLO_BUILD_SHARED_LIBS)

set(TELLO_BIN_DIR ${CMAKE_BINARY_DIR}/_deps/tello-build CACHE INTERNAL "")