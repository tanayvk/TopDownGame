cmake_minimum_required(VERSION 3.10)

project(TopDownGame)

set(CMAKE_CXX_STANDARD, 17)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

add_subdirectory(Source)

# Copy assets
file(COPY ./Assets DESTINATION .)
