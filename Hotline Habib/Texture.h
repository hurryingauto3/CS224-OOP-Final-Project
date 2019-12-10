#pragma once

#include "Game.h"

#pragma once

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(std::string Sprite);
    static void Draw(SDL_Texture *tex, SDL_Rect sRect, SDL_Rect dRect);
};
