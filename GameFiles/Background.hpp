#include "Texture.hpp"
#pragma once

class BG
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    int a, b;

public:
    BG(){};
    BG(const char *sprite, SDL_Renderer *gRenderer)
    {
        //Player::setlocation(0, 0);
        ren = gRenderer;
        obj_tex = texture::sprite(sprite, gRenderer);
        dRect.h = 1080 * 3;
        dRect.w = 720 * 3;
        dRect.x = a = 0;
        dRect.y = b = 0;
        // SDL_Texture *this1 = texture::sprite("./Sprites/Player.png", gRenderer);
        // SDL_RenderCopy(gRenderer, this1, nullptr, &dRect);
        SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
    }

    void obj_update()
    {
        // sRect.h = 208;
        // sRect.w = 208;
        // sRect.x = 0;
        // sRect.y = 0;

        dRect.h = 1080 * 3;
        dRect.w = 720 * 3;
        dRect.x = a - Game::camera.x;
        dRect.y = b - Game::camera.y;
        }

    void obj_render()
    {
        SDL_RenderCopy(ren, obj_tex, nullptr, &dRect); //sRect is null for now
    }
};