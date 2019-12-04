#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <
#include <SDL_image.h>

#endif

int showmenu(SDL_Surface *screen)
{
    Uint32 frametime;
    int x, y;
    const int NUMMENU = 3;
    const char *labels[NUMMENU] = {"Start",
                                   "Instructions",
                                   "Exit"};
    SDL_Surface *menus[NUMMENU];
    bool selected[NUMMENU] = {0, 0};
    SDL_Color color[2] = {{255, 255, 255}, {255, 0, 0}};
    menus[0] =
}