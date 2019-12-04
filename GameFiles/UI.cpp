#include "UI.hpp"

ui_simplified::ui_simplified(const char *sprite, SDL_Renderer *gRenderer)
{
    ren = gRenderer;
    obj_tex = texture::sprite(sprite, gRenderer);
    dRect.h = 1080;
    dRect.w = 720;
    dRect.x = 0;
    dRect.y = 0;

    SDL_RenderCopy(gRenderer, obj_tex, nullptr, &dRect);
}

void ui_simplified::obj_update()
{
    dRect.h = 1080;
    dRect.w = 720;
    dRect.x = 0;
    dRect.y = 0;
}

void ui_simplified::obj_render()
{
    SDL_RenderCopy(ren, obj_tex, nullptr, &dRect); //sRect is null for now
}
bool ui_simplified::start_party()
{
    return starto;
}
void ui_simplified::handle_event()
{
    SDL_Event e;
    switch (e.key.keysym.sym)
    {
    case SDLK_F4: //pressing this should kill the process
        //SDL_DestroyWindow(window);
    case SDLK_KP_ENTER || SDLK_RETURN: //pressing this key should start the game
        //     std::cout << "Started" << std::endl;
        //   Game Thegame;
        //   std::cout << "Game Object Created" << std::endl;
        //   while (Thegame.runcheck())
        //   {

        //     framestart = SDL_GetTicks();
        //     //std::cout << "Ticks got" << std::endl;
        //     Thegame.handle_event();
        //     //std::cout << "Events handled" << std::endl;
        //     Thegame.update();
        //     //std::cout << "Update game" << std::endl;
        //     Thegame.render();
        //     //std::cout << "Rendered" << std::endl;
        //     frametime = SDL_GetTicks() - framestart;
        //     if (framedelay > frametime)
        //     {
        //       SDL_Delay(framedelay - frametime);
        //     }
        //   }

        //   Thegame.clean();
        //   return 0;
    }
}