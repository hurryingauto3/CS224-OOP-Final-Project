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
    void decrease_health(float hitpoints)
    {
        health = health - hitpoints;
    }

    void spriteshift(std::string direction){};
    virtual int getx()
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