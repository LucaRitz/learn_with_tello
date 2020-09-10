include(FetchContent)
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad
        GIT_TAG        v0.1.33
)
FetchContent_MakeAvailable(glad)

message("GLAD_INCLUDE_DIRS : ${GLAD_INCLUDE_DIRS}")
