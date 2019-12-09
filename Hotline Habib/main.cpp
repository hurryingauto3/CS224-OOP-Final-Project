#include <SDL.h>
#include "Game.h"
Game *game = nullptr;

int main(int argc, char *argv[])
{
    const int FPS = 60;
    int frametime;
    int frameDelay = 1000 / FPS;
    Uint32 framestart;

    game = new Game();
    game->init("Hotline Habib", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, true);

    while (game->running())
    {
        framestart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frametime = SDL_GetTicks() - framestart;

        if (frameDelay > frametime)
        {
            SDL_Delay(frameDelay - frametime);
        }
    }

    game->clean();
    return 0;
}