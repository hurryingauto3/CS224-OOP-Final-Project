#include "UI.h"

ui_simplified::ui_simplified(char *sprite)
{
    obj_tex = TextureManager::LoadTexture(sprite);
    dRect.h = 720;
    dRect.w = 1080;
    dRect.x = 0;
    dRect.y = 0;
    endGame = false;
    SDL_RenderCopy(Game::renderer, obj_tex, nullptr, &dRect);
}

void ui_simplified::UI_Update()
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

void ui_simplified::UI_Render()
{
    SDL_RenderCopy(Game::renderer, obj_tex, nullptr, &dRect); //sRect is null for now
}
bool ui_simplified::start_party()
{
    return starto;
}

void ui_simplified::setEndGame(bool gameState)
{
    endGame = gameState;
}
