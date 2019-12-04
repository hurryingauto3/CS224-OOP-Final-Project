#include <string>
#include "SDL.h"
#include <SDL_image.h>
#pragma once

class MasterObject
{
private:
    int x;
    int y;
    int height;
    int width;
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    char Obj_type;

public:
    int getx();
    int gety();
    void setlocation(int x1, int y2);
    int getheight();
    int getwidth();
    void setdimension(int w, int h);

    void obj_update();
    void obj_render();
    SDL_Rect getsrekt();
    SDL_Rect getdrekt();
};
