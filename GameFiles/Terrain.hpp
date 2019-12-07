
#pragma once
#include "Master.hpp"

class Terrain : public MasterObject

{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:
    float width;
    float height;

    bool passable;
};

class Door : public Terrain
{
private:
    bool state_open;

public:
    Door()
    {
        state_open = false;
        this->height = 5;
        this->width = 1;
    };
    void openclose_door()
    {
        if (state_open == false)
        {
            state_open = true;
            this->passable = true;
        }
        if (state_open == true)
        {
            state_open = false;
            this->passable = false;
        }
    };
};

class Wall : public Terrain
{
private:
    bool passable;

public:
    Wall()
    {
        passable = false;
        this->width = 5;
        this->height = 5;
    }
};

class Window : public Terrain
{
private:
    bool status_broken;

public:
    void breakwindow()
    {
        if (status_broken == false)
        {
            status_broken = true;
            this->passable = true;
        }
    }
    Window()
    {
        status_broken = false;
        this->height = 5;
        this->width = 1;
    }
};
