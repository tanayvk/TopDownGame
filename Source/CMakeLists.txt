add_library(Game STATIC Game.cpp Actors/Actor.cpp Actors/ActorComponent.cpp Actors/SpriteComponent.cpp)
target_link_libraries(Game ${SDL2_LIBRARIES})

add_executable(Main Main.cpp)
target_link_libraries(Main Game)
