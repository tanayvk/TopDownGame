add_library(Game STATIC Game.cpp
                        Renderer.cpp
                        Actors/Actor.cpp
                        Actors/ActorComponent.cpp
                        Actors/SpriteComponent.cpp
                        Actors/MoveComponent.cpp )
target_link_libraries(Game PRIVATE SDL2::SDL2main SDL2::SDL2-static SDL2::SDL2_image)

add_executable(Main Main.cpp)
target_link_libraries(Main Game)
