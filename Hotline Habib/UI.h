#include <iostream>
#include "Game.h"
#include "Texture.h"
using namespace std;

#pragma once

class ui_simplified
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    bool starto;
    bool endGame;

public:
    void setEndGame(bool);
    ui_simplified();             //default constructor
    ui_simplified(char *sprite); //in cpp
    ~ui_simplified();            //default deconstructor
    void UI_Update();            //in cpp
    void UI_Render();            //in cpp
    bool start_party();          //in cpp
};
