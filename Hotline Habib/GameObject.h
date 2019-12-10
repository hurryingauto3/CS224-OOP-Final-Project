#pragma once
#include "Game.h"
#include <cmath>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{

private:
    std::string Sprite;
    int xpos;
    int ypos;
    SDL_Texture *Obj_Tex;
    SDL_Rect sRect, dRect;
    bool animated = false;
    int frames = 0;
    int speed = 100;

public:
    GameObject(){};
    GameObject(std::string Sprite, int xpos, int ypos);
    GameObject(std::string Sprite, int xpos, int ypos, int frames, int speed);
    ~GameObject();

    void Render();
    void Update();

    int getx();
    int gety();
    void setx(int x) { this->xpos = x; }
    void sety(int y) { this->ypos = y; }

    void Setloc(int x, int y);
    void ChangeSprite(std::string title);

    SDL_Rect GetDRect() { return dRect; }
};

#endif