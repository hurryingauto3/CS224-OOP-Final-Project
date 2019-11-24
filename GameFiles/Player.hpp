#include "People.hpp"
#include "Texture.hpp"
#include <iostream>
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
    Player(const char *sprite, SDL_Renderer *r)
    {
        Player::setlocation(0, 0);
        ren = r;
        obj_tex = texture::sprite(sprite, r);
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
        SDL_RenderCopy(ren, obj_tex, &sRect, &dRect);
    }
};