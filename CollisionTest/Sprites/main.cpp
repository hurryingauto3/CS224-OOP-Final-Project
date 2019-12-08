#include "Game.hpp"
#include <SDL.h>
#include <SDL_Image.h>

Uint32 framestart;
int frametime;

const int fps = 60;
const int framedelay = 1000 / fps;

int main(int argv, char **args)
{
    framestart = SDL_GetTicks();

    Game *game;
    std::cout << "Game Rendered" << std::endl;
    game = new Game();
    while (game->RunCheck())
    {
        game->handle_event();
        game->render();
        game->update();
    }

    frametime = SDL_GetTicks() - framestart;
    if (framedelay > frametime)
    {
        SDL_Delay(framedelay - frametime);
    }

    return 0;
}