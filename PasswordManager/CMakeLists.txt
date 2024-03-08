cmake_minimum_required(VERSION 3.25)
project(PasswdManager)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG a0b8a92e3d1532361c2f7feb63babc5c18d00ef2
)

FetchContent_MakeAvailable(fmt)

add_executable(PasswdManager main.cpp CommandHandler.cpp PasswordManager.cpp FileManager.cpp Encryption.cpp)
target_link_libraries(PasswdManager fmt)
