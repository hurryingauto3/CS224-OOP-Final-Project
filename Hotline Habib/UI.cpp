#include "UI.h"

uicomp::uicomp(std::string sprite)
{
    obj_tex = TextureManager::LoadTexture(sprite);
    dRect.h = 720;
    dRect.w = 1080;
    dRect.x = 0;
    dRect.y = 0;
    endGame = false;
    SDL_RenderCopy(Game::renderer, obj_tex, nullptr, &dRect);
}

void uicomp::SetSprite(std::string Sprite)
{
    this->Sprite = Sprite;
    this->obj_tex = TextureManager::LoadTexture(this->Sprite);
}

void uicomp::UI_Update()
{
    dRect.h = 720;
    dRect.w = 1080;
    dRect.x = 0;
    dRect.y = 0;

    if (endGame)
    {
        std::cout << "Ending" << std::endl;
        exit(0);
    }
}

void uicomp::UI_Render()
{
    SDL_RenderCopy(Game::renderer, obj_tex, nullptr, &dRect); //sRect is null for now
}

void uicomp::setEndGame(bool gameState)
{
    endGame = gameState;
}

bool uicomp::getstart()
{
    return Start;
}

void uicomp::setstart(bool Start)
{
    this->Start = Start;
}