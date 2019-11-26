
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
#include "Background.hpp"
#include "LinkedList.hpp"
#pragma once
class Game
{
private:
    bool is_running;
    LinkedList *Obj;
    Player *A;
    Enemy *B;
    Wall *W;
    BG *C;
    SDL_Window *window;
    SDL_Renderer *grenderer;

public:
    bool runcheck(); //Returns the status of the game
    void update();
    void render();
    void clean(); //Frees all resources upon quitting
    void handle_event();
    Game();
    ~Game();
};