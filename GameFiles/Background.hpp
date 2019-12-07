#include "Texture.hpp"
class Game;
#pragma once

class BG
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:
    BG(){};
    BG(const char *sprite, SDL_Renderer *gRenderer)
    {
        ren = gRenderer;
        obj_tex = texture::sprite(sprite, gRenderer);
        dRect.h = 1080 * 3;
        dRect.w = 720 * 3;
        dRect.x = 0;
        dRect.y = 0;
        SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
    }

    void obj_update()
    {

        dRect.h = 1080 * 3;
        dRect.w = 720 * 3;
        dRect.x = 0;
        dRect.y = 0;
    }
    void obj_render()
    {
        SDL_RenderCopy(ren, obj_tex, nullptr, &dRect); //sRect is null for now
    }
};