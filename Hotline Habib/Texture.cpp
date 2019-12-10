#include "Texture.h"

SDL_Texture *TextureManager::LoadTexture(std::string Sprite)
{
    const char *c = Sprite.c_str();
    SDL_Surface *temp = IMG_Load(c);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
    SDL_FreeSurface(temp);
    return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect sRect, SDL_Rect dRect)
{
    SDL_RenderCopy(Game::renderer, tex, &sRect, &dRect);
}