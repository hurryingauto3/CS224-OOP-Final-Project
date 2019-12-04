#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.hpp"
#include "Game.hpp"
using namespace std;

#pragma once

class ui_simplified
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    bool starto;

public:
    ui_simplified();                                            //default constructor
    ui_simplified(const char *sprite, SDL_Renderer *gRenderer); //in cpp
    ~ui_simplified();                                           //default deconstructor
    void obj_update();                                          //in cpp
    void obj_render();                                          //in cpp
    bool start_party();                                         //in cpp
    void handle_event();
};