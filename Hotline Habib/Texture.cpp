#include "Texture.h"

SDL_Texture *TextureManager::LoadTexture(char *Sprite)
{
    SDL_Surface *temp = IMG_Load(Sprite);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
    SDL_FreeSurface(temp);
    return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect sRect, SDL_Rect dRect)
{
    SDL_RenderCopy(Game::renderer, tex, &sRect, &dRect);
}