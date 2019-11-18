#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Terrain.hpp"

class Game
{
private:
    bool is_running;
    Player A;
    SDL_Window *window;
    SDL_Renderer *grenderer;

public:
    bool is_runningzz();
    void update();
    void render();
    void clean();
    void HandleEvent();
    void init();
};