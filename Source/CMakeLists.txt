add_library(Game STATIC Game.cpp)

add_executable(Main Main.cpp)
target_link_libraries(Main ${SDL2_LIBRARIES})
target_link_libraries(Main Game)
