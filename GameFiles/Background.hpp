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
        dRect.h = 1300;
        dRect.w = 1800;
        dRect.x = 0;
        dRect.y = 0;
        sRect = {0, 0, 1800, 1300};
        SDL_RenderCopy(gRenderer, obj_tex, &sRect, nullptr);
    }

    void obj_update(int x, int y)
    {

        // dRect.h = 720 * 3;
        // dRect.w = 1080 * 3;
        // dRect.x = 0;
        // dRect.y = 0;
        renderQuad.x = x;
        renderQuad.y = y;
        renderQuad.w = 1800 * 1.5;
        renderQuad.h = 1300 * 1.5;
    }
    void obj_render(int x, int y, SDL_Rect *clip)
    {
        if (clip != NULL)
        {
            std::cout << renderQuad.x << std::endl;

            SDL_RenderCopy(ren, obj_tex, &sRect, &renderQuad);
        }
    }
    SDL_Rect getsrect()
    {
        return sRect;
    }
    // SDL_Rect getdrect()
    // {
    //     return dRect;
    // }
};
