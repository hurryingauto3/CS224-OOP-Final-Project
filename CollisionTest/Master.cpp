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
    MasterObject::setsRect(0, 0, 208, 208);
    MasterObject::setdRect(MasterObject::getx(), MasterObject::gety(), 50, 50);
}

void MasterObject::obj_render(SDL_Renderer *ren, SDL_Texture *obj_tex, SDL_Rect &sRect, SDL_Rect &dRect)
{
    SDL_RenderCopy(ren, obj_tex, &sRect, &dRect); //sRect is null for now
}

void MasterObject::setx(int x) { this->x = x; }

void MasterObject::sety(int y) { this->y = y; }

void MasterObject::setTex(SDL_Texture *Obj_tex)
{
    this->obj_tex = Obj_tex;
}
void MasterObject::setsRect(int x, int y, int h, int w)
{
    this->sRect.x = x;
    this->sRect.y = y;
    this->sRect.h = h;
    this->sRect.w = w;
}
void MasterObject::setdRect(int x, int y, int h, int w)
{
    this->dRect.x = x;
    this->dRect.y = y;
    this->dRect.h = h;
    this->dRect.w = w;
}
void MasterObject::setRen(SDL_Renderer *ren)
{
    this->ren = ren;
}
SDL_Texture *MasterObject::getTex()
{
    return this->obj_tex;
}
SDL_Rect &MasterObject::getsrekt()
{
    return this->sRect;
}
SDL_Rect &MasterObject::getdrekt()
{
    return this->dRect;
}
SDL_Renderer *MasterObject::getren()
{
    return this->ren;
}
