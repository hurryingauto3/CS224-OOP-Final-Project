#include "People.hpp"
#include "Texture.hpp"
#include <iostream>
#include <SDL.h>
#include <cmath>

#pragma once

class Player : public People
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    int x;
    int y;
    int speed = 7;

public:
    void shoot()
    {
        std::cout << "Shot fired" << std::endl;
    };

    Player(){};

    virtual int getx()
    {
        return x;
    }

    virtual int gety()
    {
        return y;
    }
    int getSpeed()
    {
        return speed;
    }

    virtual void setlocation(int x1, int y2)
    {
        x = x1;
        y = y2;
    }

    Player(const char *sprite, SDL_Renderer *gRenderer)
    {
        Player::setlocation(200, 200);
        ren = gRenderer;
        obj_tex = texture::sprite(sprite, gRenderer);
        dRect.h = 720;
        dRect.w = 1080;
        dRect.x = 0;
        dRect.y = 0;

        SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
    }

    void obj_update()
    {
        // sRect.h = 208;
        // sRect.w = 208;
        // sRect.x = 0;
        // sRect.y = 0;

        dRect.h = 128;
        dRect.w = 128;
        dRect.x = getx();
        dRect.y = gety();

        angle();
    }

    void obj_render()
    {
        SDL_RenderCopyEx(ren, obj_tex, nullptr, &dRect, angle(), nullptr, SDL_FLIP_HORIZONTAL); //sRect is null for now
    }
    double angle()
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        int a = x;
        int b = y;
        int base = getx() - a;
        int height = gety() - b;
        double ans = atan2(height, base) * 180 / 3.14159265;
        return ans;
    }
};
