#pragma once
#include "Game.h"
#include <cmath>

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
    bool IsPlayerClosebool;

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

    bool IsPlayerClose(GameObject *A)
    {
        if (pow(pow(this->getx() - A->getx(), 2) + pow(this->gety() - A->gety(), 2), 0.5) < 200)
        {
            this->IsPlayerClosebool = true;
            return true;
        }
        else
        {
            this->IsPlayerClosebool = false;
            return false;
        }
    }

    void ApproachPlayer(GameObject *A)
    {
        if (this->getx() != A->getx() | this->gety() != A->gety())
        {
            if (this->getx() > A->getx())
            {
                this->Setloc(this->getx() - 1, this->gety());
            }
            if (this->getx() < A->getx())
            {
                this->Setloc(this->getx() + 1, this->gety());
            }
            if (this->gety() > A->gety())
                this->Setloc(this->getx(), this->gety() - 1);
        }
        if (this->gety() < A->gety())
        {
            this->Setloc(this->getx(), this->gety() + 1);
        }
    }

    bool returnclose()
    {

        return this->IsPlayerClosebool;
    }
};
