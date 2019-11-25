#include "Player.hpp"

#pragma once
class Enemy : public People
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:
    Enemy(){};
    // Enemy(int xloc, int yloc)
    // {
    //     this->setlocation(xloc, yloc);
    // };
    // Enemy(int xloc, int yloc, int health) : Enemy(xloc, yloc){};

    // Enemy(int xloc, int yloc, int health, int attack) : Enemy(xloc, yloc, health){};
    Enemy(const char *sprite, SDL_Renderer *r)
    {
        Enemy::setlocation(0, 0);
        ren = r;
        obj_tex = texture::sprite(sprite, r);
    }

    void obj_update()
    {
        sRect.h = 208;
        sRect.w = 208;
        sRect.x = 0;
        sRect.y = 0;

        dRect.h = 128;
        dRect.w = 128;
        dRect.x = getx();
        dRect.y = gety();
    }

    void obj_render()
    {
        SDL_RenderCopy(ren, obj_tex, &sRect, &dRect);
    }

    void ApproachPlayer(Player *A) //Player is a pointer now
    {
        if (this->getx() != A->getx() and this->gety() != A->gety())
        {
            if (this->getx() > A->getx())
            {
                this->setlocation(this->getx() - 5, this->gety());
            }
            else
            {
                this->setlocation(this->getx() + 5, this->gety());
            }
            if (this->gety() > A->gety())
                this->setlocation(this->getx(), this->gety() - 5);
        }
        else if (this->gety() < A->gety())
        {
            this->setlocation(this->getx(), this->gety() + 5);
        }
    };
};
