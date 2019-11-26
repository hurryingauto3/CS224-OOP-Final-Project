#include "Terrain.hpp"

void Terrain::obj_update()
{
    sRect.h = 208;
    sRect.w = 208;
    sRect.x = 0;
    sRect.y = 0;

    dRect.h = 128;
    dRect.w = 128;
    dRect.x = Terrain::getx();
    dRect.y = Terrain::gety();
}

void Terrain::obj_render()
{
    SDL_RenderCopy(ren, obj_tex, nullptr, &dRect); //sRect is null for now
}

float Terrain::getx()
{
    return this->x_cor;
}
float Terrain::gety()
{
    return this->y_cor;
}

