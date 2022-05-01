cmake_minimum_required(VERSION 3.20)
project(Thauma-Tools)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(SDL2 GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git" GIT_TAG "release-2.0.22")
FetchContent_MakeAvailable(SDL2)

add_subdirectory(Numina)
add_subdirectory(Thaumaturge)
