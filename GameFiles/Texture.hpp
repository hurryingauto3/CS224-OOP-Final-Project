#include <SDL.h>
#include <SDL_image.h>
#pragma once

class texture
{
public:
    static SDL_Texture *sprite(const char *filename, SDL_Renderer *r);
};