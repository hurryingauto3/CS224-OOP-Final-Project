#include "Player.hpp"
#pragma once
class Enemy : public People
{
private:
public:
    Enemy(){};
    // Enemy(int xloc, int yloc)
    // {
    //     this->setlocation(xloc, yloc);
    // };
    // Enemy(int xloc, int yloc, int health) : Enemy(xloc, yloc){};

    // Enemy(int xloc, int yloc, int health, int attack) : Enemy(xloc, yloc, health){};
    void ApproachPlayer(Player A)
    {
        if (this->getx() != A.getx() and this->gety() != A.gety())
        {
            if (this->getx() > A.getx())
            {
                this->setlocation(this->getx() - 5, this->gety());
            }
            else
            {
                this->setlocation(this->getx() + 5, this->gety());
            }
            if (this->gety() > A.gety())
                this->setlocation(this->getx(), this->gety() - 5);
        }
        else if (this->gety() < A.gety())
        {
            this->setlocation(this->getx(), this->gety() + 5);
        }
    };
};
