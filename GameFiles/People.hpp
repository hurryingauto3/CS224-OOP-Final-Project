#include <iostream>
#include "Master.hpp"
#pragma once
class People : public MasterObject
{
private:
    float health;
    float attack;
    float width;
    float height;
    int x;
    int y;

public:
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void decrease_health(float hitpoints)
    {
        health = health - hitpoints;
    }

    void spriteshift(std::string direction){};

    People()
    {
        health = 100;
        width = 5;
        height = 10;

        this->setlocation(100, 100);
    }

    void sethealth(float health)
    {
        this->health = health;
    }

    void setattack(float attack)
    {
        this->attack = attack;
    }
};