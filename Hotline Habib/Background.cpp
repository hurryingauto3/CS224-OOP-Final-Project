#include "Background.h"
Background::Background(){};

Background::Background(std::string sprite)
{
    ren = Game::renderer;
    obj_tex = TextureManager::LoadTexture(sprite);
    dRect.w = 1080 * 2;
    dRect.h = 720 * 2;
    dRect.x = 0;
    dRect.y = 0;
    SDL_RenderCopy(Game::renderer, obj_tex, &dRect, nullptr);
}

void Background::BG_Update()
{
    SDL_RenderCopy(Game::renderer, obj_tex, &dRect, nullptr);
}
void Background::BG_Cam(int x, int y)
{
    SDL_RenderCopy(Game::renderer, obj_tex, &dRect, nullptr);
    dRect.w = 1080;
    dRect.h = 720;
    dRect.x = x - 560;
    dRect.y = y - 360;

    if (dRect.x < 0)
        dRect.x = 0;
    if (dRect.y < 0)
        dRect.y = 0;
}
void Background::BG_Render()
{
    SDL_RenderCopy(Game::renderer, obj_tex, &dRect, nullptr); //sRect is null for now
}

void Background::ChangeSprite(std::string Sprite)
{
    this->Sprite = Sprite;
    this->obj_tex = TextureManager::LoadTexture(this->Sprite);
}