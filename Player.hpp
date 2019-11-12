#include "People.hpp"
#include <iostream>
class Player : public People
{
public:
    void shoot(){};
    Player()
    {
        Player::setlocation(0, 0);
    }
};