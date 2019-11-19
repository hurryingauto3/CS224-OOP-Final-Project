#include "People.hpp"
#include <iostream>
#pragma once
class Player : public People
{
public:
    void shoot()
    {
        std::cout << "Shot fired" << std::endl;
    };
    void shoot(){};

    Player()
    {
        Player::setlocation(0, 0);
    }
};