#include "Master.hpp"
int MasterObject::getx()
{
    return this->x;
}
int MasterObject::gety()
{
    return this->y;
}
void MasterObject::obj_update()
{
    sRect.h = 208;
    sRect.w = 208;
    sRect.x = 0;
    sRect.y = 0;

    dRect.h = 128;
    dRect.w = 128;
    dRect.x = MasterObject::getx();
    dRect.y = MasterObject::gety();
}

void MasterObject::obj_render()
{
    SDL_RenderCopy(ren, obj_tex, &sRect, &dRect); //sRect is null for now
}

SDL_Rect MasterObject::getsrekt()
{
    return sRect;
}
SDL_Rect MasterObject::getdrekt()
{
    return dRect;
}