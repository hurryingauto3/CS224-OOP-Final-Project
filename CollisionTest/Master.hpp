#include <SDL.h>
#include <SDL_image.h>
#pragma once
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

    void setx(int x);
    void sety(int y);

    void setTex(SDL_Texture *);
    void setsRect(int x, int y, int h, int w);
    void setdRect(int x, int y, int h, int w);
    void setRen(SDL_Renderer *);

    SDL_Texture *getTex();
    SDL_Rect &getsrekt();
    SDL_Rect &getdrekt();
    SDL_Renderer *getren();

    void obj_update();
    void obj_render(SDL_Renderer *ren, SDL_Texture *obj_tex, SDL_Rect &sRect, SDL_Rect &dRect);
};
