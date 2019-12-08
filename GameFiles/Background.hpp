#include "Texture.hpp"
class Game;
#pragma once

class BG
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    SDL_Rect renderQuad;

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

    void obj_update(SDL_Rect *clip)
    {

        dRect.h = 1080 * 3;
        dRect.w = 720 * 3;
        dRect.x = 0;
        dRect.y = 0;

        renderQuad.x = clip->x;
        renderQuad.y = clip->y;
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    void obj_render(int x, int y, SDL_Rect *clip)
    {
        if (clip != NULL)
        {
            renderQuad.x = x;
            renderQuad.y = y;
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }
    }
};