#include <iostream>

#include "Master.hpp"
#pragma once
class People : public MasterObject
{
private:
    float width;
    float height;

public:
    People()
    {
        width = 5;
        height = 10;

    }

};