#include "People.hpp"
#include "Texture.hpp"
#include <iostream>
#include <SDL.h>

#pragma once

class Player : public People
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:
    void shoot()
    {
        std::cout << "Shot fired" << std::endl;
    };

    Player(){};

    Player(const char *sprite, SDL_Renderer *gRenderer)
    {
        Player::setlocation(0, 0);
        ren = gRenderer;
        obj_tex = texture::sprite(sprite, gRenderer);
        dRect.h = 571;
        dRect.w = 999;
        dRect.x = 0;
        dRect.y = 0;
        SDL_Texture *this1 = texture::sprite("./Sprites/Player.png", gRenderer);
        SDL_RenderCopy(gRenderer, this1, NULL, &dRect);
        SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
    }

    void obj_update()
    {
        sRect.h = 208;
        sRect.w = 208;
        sRect.x = 0;
        sRect.y = 0;

        dRect.h = 128;
        dRect.w = 128;
        dRect.x = People::getx();
        dRect.y = People::gety();
    }

    void obj_render()
    {
        SDL_RenderCopy(ren, obj_tex, nullptr, &dRect); //sRect is null for now
    }
};