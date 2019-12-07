#include "Game.hpp"
#include <SDL.h>
#include <SDL_Image.h>

Uint32 framestart;
int frametime;

const int fps = 120;
const int framedelay = 1000 / fps;

int main(int argv, char **args)
{
    framestart = SDL_GetTicks();

    Game *game = new Game();
    std::cout << "Game Created" << std::endl;

    while (game->RunCheck())
    {

        game->render();
        // std::cout << "Game Rendered" << std::endl;
        game->update();
        // std::cout << "Game Updated" << std::endl;
        game->handle_event();
        // std::cout << "Events Handled" << std::endl;
    }

    frametime = SDL_GetTicks() - framestart;
    if (framedelay > frametime)
    {
        SDL_Delay(framedelay - frametime);
    }

    return 0;
}