#include <string>
#include "SDL.h"

class MasterObject
{
private:
    int x;
    int y;

    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    char Obj_type;

public:
    int getx();
    int gety();
    void obj_update();
    void obj_render();
};