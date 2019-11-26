#include "Player.hpp"
#include "Texture.hpp"
#pragma once

class Enemy : public People
{

private:
    bool PlayernearBy;

    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:

    Enemy()
    {
        PlayernearBy = false;
    };

    // Enemy(int xloc, int yloc, int health, int attack) : Enemy(xloc, yloc, health){};
    Enemy(const char *sprite, SDL_Renderer *r, int x, int y) : Enemy()
    {
        Enemy::setlocation(x, y);
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

    Enemy(const char *sprite, SDL_Renderer *r, int x, int y, float health) : Enemy(sprite, r, x, y)
    {
        Enemy::sethealth(health);
    }

    Enemy(const char *sprite, SDL_Renderer *r, int x, int y, float health, float attack) : Enemy(sprite, r, x, y, health)
    {
        Enemy::setattack(attack);
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


    void Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    {
        if (this->gety() == y1 && this->getx() != x2)
        {
            this->setlocation(this->getx() + 1, this->gety());
            this->obj_update();
        }
        else if (this->getx() == x2 && this->gety() != y3)
        {
            this->setlocation(this->getx(), this->gety() + 1);
            this->obj_update();
        }
        else if (this->gety() == y3 && this->getx() != x1)
        {
            this->setlocation(this->getx() - 1, this->gety());
            this->obj_update();
        }
        else if (this->getx() == x1 && this->gety() != y1)
        {
            this->setlocation(this->getx(), this->gety() - 1);
            this->obj_update();
        }
    };

    void IsPlayerClose(Player A)
    {
        if (pow(pow(this->getx() - A.getx(), 2) + pow(this->gety() - A.gety(), 2), 0.5) < 200)
        {
            Enemy::PlayernearBy = true;
        }
        else
        {
            Enemy::PlayernearBy = false;
        }
    };

    void ApproachPlayer(Player A)
    {
        if (this->getx() != A.getx() || this->gety() != A.gety())
        {
            if (this->getx() > A.getx())
            {
                this->setlocation(this->getx() - 1, this->gety());
            }
            if (this->getx() < A.getx())
            {
                this->setlocation(this->getx() + 1, this->gety());
            }
            if (this->gety() > A.gety())
                this->setlocation(this->getx(), this->gety() - 1);
        }
        if (this->gety() < A.gety())
        {
            this->setlocation(this->getx(), this->gety() + 1);
        }
    };

    bool getplayercloseby()
    {
        return Enemy::PlayernearBy;
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
