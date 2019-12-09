#pragma once
#include "Texture.h"
#include "Game.h"

class Background
{
private:
    char *Sprite;
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:
    Background();
    Background(char *sprite);
    void BG_Update();
    void BG_Render();
    void ChangeSprite(char *Sprite);
    void BG_Cam(int x, int y);
};