#pragma once
#include "Game.h"
#include "Texture.h"
#include <cmath>

class GameObject
{

private:
    std::string Sprite;
    int xpos, ypos;
    SDL_Texture *Obj_Tex;
    SDL_Rect sRect, dRect;
    bool animated = false;
    int frames = 0;
    int speed = 100;
    bool IsPlayerClosebool;

public:
    static const int DOT_VEL = 5;
    int mVelX, mVelY;

    GameObject();
    GameObject(std::string Sprite, int xpos, int ypos);
    GameObject(std::string Sprite, int xpos, int ypos, int frames, int speed);

    void Render();
    void Update();

    int getx();
    int gety();
    void setx(int x) { this->xpos = x; }
    void sety(int y) { this->ypos = y; }

    void Setloc(int x, int y);
    void ChangeSprite(std::string title);
    SDL_Rect GetDRect() { return dRect; }
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

    void Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    {
        if (this->gety() == y1 && this->getx() != x2)
        {
            this->Setloc(this->getx() + 1, this->gety());
            this->Update();
        }
        else if (this->getx() == x2 && this->gety() != y3)
        {
            this->Setloc(this->getx(), this->gety() + 1);
            this->Update();
        }
        else if (this->gety() == y3 && this->getx() != x1)
        {
            this->Setloc(this->getx() - 1, this->gety());
            this->Update();
        }
        else if (this->getx() == x1 && this->gety() != y1)
        {
            this->Setloc(this->getx(), this->gety() - 1);
            this->Update();
        }
    }
};
