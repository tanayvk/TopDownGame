add_subdirectory(ThirdParty/SDL2)

include_directories(ThirdParty/SDL2/include)
include_directories(ThirdParty/stb_image/include)

add_library(Game STATIC Game.cpp
                        Renderer.cpp
                        Actors/Actor.cpp
                        Actors/ActorComponent.cpp
                        Actors/SpriteComponent.cpp
                        Actors/MoveComponent.cpp )

target_link_libraries(Game PRIVATE SDL2 SDL2main)

add_executable(Main Main.cpp)
target_link_libraries(Main Game)
