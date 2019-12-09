#include <iostream>
#include "Master.hpp"
#pragma once
class People : public MasterObject
{
private:
    // float health; //we don't need these anymore
    // float attack;
    float width;
    float height;
    int x;
    int y;

public:
<<<<<<< HEAD
     {
        return x;
    }

    virtual int gety()
    {
        return y;
    }

    virtual void setlocation(int x1, int y2)
    {
        x = x1;
        y = y2;
    }
=======
    // void decrease_health(float hitpoints) //we don't need this anymore
    // {
    //     health = health - hitpoints;
>>>>>>> 3c777f5de518ed35ad69f143d2106eb9d5641220

    People()
    {
        //health = 100; //we don't need this anymore
        width = 5;
        height = 10;
    }

    // void sethealth(float health) //we don't need these anymore
    // {
    //     this->health = health;
    // }

    // void setattack(float attack)
    // {
    //     this->attack = attack;
    // }
};