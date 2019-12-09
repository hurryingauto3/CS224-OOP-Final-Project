#pragma once
#include "Game.h"

class GameObject
{

private:
    char *Sprite;
    int xpos;
    int ypos;
    SDL_Texture *Obj_Tex;
    SDL_Rect sRect, dRect;
    int framewidth, frameheight;
    int texturewidth, textureheight;
    bool animated = false;
    int frames = 0;
    int speed = 100;

public:
    GameObject(){};
    GameObject(char *Sprite, int xpos, int ypos);
    GameObject(char *Sprite, int xpos, int ypos, int frames, int speed);
    ~GameObject();
    void Render();
    void Update();
    int getx();
    int gety();
    void Setloc(int x, int y);

    void Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    // SDL_Texture *GetTex();
    // int *GetTexW();
    // int *GetTexH();
    // int *GetFrameW();
    // int *GetFrameH();
    void ChangeSprite(char *title);
};
