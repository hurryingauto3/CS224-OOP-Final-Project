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
    // void decrease_health(float hitpoints) //we don't need this anymore
    // {
    //     health = health - hitpoints;

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