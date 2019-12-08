#include "Texture.hpp"

SDL_Texture *texture::sprite(const char *filename, SDL_Renderer *r)
{
    SDL_Surface *temp = IMG_Load(filename);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(r, temp);
    SDL_FreeSurface(temp);

    return tex;
}