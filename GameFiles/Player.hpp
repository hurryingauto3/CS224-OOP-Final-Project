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
    SDL_Rect sRect, dRect, camera;
    SDL_Renderer *ren;
    int x, y;
    int a = 7;

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
        return a;
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
        dRect.x = x;
        dRect.y = y;
        camera = {x, y, 1080, 720};

        SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
    }

    void obj_update()
    {

        dRect.h = 128;
        dRect.w = 128;
        dRect.x = getx();
        dRect.y = gety();

        angle();

        // camera.x = getx() - 540;
        // camera.y = gety() - 360;

        if (camera.x < 0)
        {
            camera.x = 0;
        }
        if (camera.y < 0)
        {
            camera.y = 0;
        }
        if (camera.x + camera.w >= 1800)
        {
            camera.x = 1800 - camera.w;
        }
        if (camera.y + camera.h >= 1300)
        {
            camera.y = 1300 - camera.h;
        }
    }

    void obj_render()
    {
        dRect = {x - camera.x, y - camera.y, dRect.w, dRect.h};
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
