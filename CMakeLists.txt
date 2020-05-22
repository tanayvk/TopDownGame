cmake_minimum_required(VERSION 3.10)

project(PlatformerShooter)

set(CMAKE_CXX_STANDARD, 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

add_subdirectory(Source)

