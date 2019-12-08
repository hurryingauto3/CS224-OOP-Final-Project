#include <SDL.h>
#include <SDL_image.h>
//SDL Included
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
//Other Libraries Included
#include "Character.hpp"
#include "Terrain.hpp"
class Game
{
private:
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *grenderer;
    Character *A;
    Character *B[10];
    Wall *W;
    Door *D;

    SDL_Rect top = {0, 0, 1080, 0};
    SDL_Rect left = {0, 0, 0, 720};
    SDL_Rect right = {1080, 0, 0, 720};
    SDL_Rect bottom = {0, 720, 1080, 0};

public:
    bool RunCheck(); //Returns the status of the game
    void update();
    void render();
    void clean(); //Frees all resources upon quitting
    void handle_event();
    Game();
    ~Game();

    bool collision(SDL_Rect a, SDL_Rect b)
    {
        if (a.y >= b.y + 50)
        {
            return false;
        }
        if (a.x >= b.x + 50)
        {
            return false;
        }
        if (a.y + 50 <= b.y)
        {
            return false;
        }
        if (a.x + 50 <= b.x)
        {
            return false;
        }
        if (a.y <= top.y | a.y >= bottom.y)
        {
            return false;
        }
        if (a.x <= left.x | a.x >= right.x)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
