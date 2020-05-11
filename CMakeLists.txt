cmake_minimum_required(VERSION 3.10)

project(PlatformerShooter)

set(CMAKE_CXX_STANDARD, 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Game Source/Main.cpp)
target_link_libraries(Game ${SDL2_LIBRARIES})
