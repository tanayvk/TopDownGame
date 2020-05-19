#include "Game.h"
#include <iostream> 

int main(int argc, char* argv[])
{
    Game* game = new Game();
    if (!game->Initialize())
    {
        std::cout << "Error with initialization." << std::endl;
        return 1;
    }

    SDL_Log("Game started!\n");
    while ( game->IsRunning() )
    {
        game->Loop();
    }

    game->CleanUp();

    return 0;
}
