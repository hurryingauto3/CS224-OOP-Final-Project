#include <SDL.h>
#include <SDL_image.h>
//SDL Included
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
//Other Libraries Included
#include "Character.hpp"

class Game
{
private:
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *grenderer;
    Character *A;
    Character *B[10];

public:
    bool RunCheck(); //Returns the status of the game
    void update();
    void render();
    void clean(); //Frees all resources upon quitting
    void handle_event();
    Game();
    ~Game();
    SDL_Rect *Collider();
};