#include <SDL.h>
#include "Game.h"

Game *game = nullptr;

const int FPS = 60;
int frametime;
int frameDelay = 1000 / FPS;
Uint32 framestart;

int main(int argc, char *argv[])
{

    game = new Game();
    game->init("Hotline Habib", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);

    framestart = SDL_GetTicks();

    game->run();

    frametime = SDL_GetTicks() - framestart;
    if (frameDelay > frametime)
        SDL_Delay(frameDelay - frametime);

    game->clean();

    return 0;
}