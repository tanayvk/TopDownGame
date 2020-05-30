cmake_minimum_required(VERSION 3.10)

project(TopDownGame)

set(CMAKE_CXX_STANDARD, 17)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(Source)

# Copy assets
file(COPY ./Assets DESTINATION .)
