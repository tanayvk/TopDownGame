add_library(Game STATIC Game.cpp)
target_link_libraries(Game ${SDL2_LIBRARIES})

add_executable(Main Main.cpp)
target_link_libraries(Main Game)
