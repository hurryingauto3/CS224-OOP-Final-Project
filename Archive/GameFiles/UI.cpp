#include "UI.hpp"

ui_simplified::ui_simplified(const char *sprite, SDL_Renderer *gRenderer)
{
    ren = gRenderer;
    obj_tex = texture::sprite(sprite, gRenderer);
    dRect.h = 720;
    dRect.w = 1080;
    dRect.x = 0;
    dRect.y = 0;
    endGame = false;
    SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
}

void ui_simplified::obj_update()
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

void ui_simplified::obj_render()
{
    SDL_RenderCopy(ren, obj_tex, nullptr, &dRect); //sRect is null for now
}
bool ui_simplified::start_party()
{
    return starto;
}

void ui_simplified::setEndGame(bool gameState)
{
    endGame = gameState;
}
