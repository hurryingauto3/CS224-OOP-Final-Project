#include <iostream>
#include "Game.h"
#include "Texture.h"
using namespace std;

#pragma once
#ifndef UICOMP_H
#define UICOMP_H

class uicomp
{
private:
    std::string Sprite;
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    bool Up;
    bool Start;
    bool endGame;

public:
    void SetSprite(std::string);
    bool getstart();
    void setstart(bool);
    void setEndGame(bool);
    bool getstate();
    uicomp();                   //default constructor
    uicomp(std::string sprite); //in cpp
    ~uicomp();                  //default deconstructor
    void UI_Update();           //in cpp
    void UI_Render();
    void setUP(bool U) { this->Up = U; }
    bool getUp() { return this->Up; }
    //in cpp        //in cpp
};

#endif