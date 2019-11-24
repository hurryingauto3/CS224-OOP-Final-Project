#include <iostream>
class People
{
private:
    float health;
    float x_location;
    float y_location;
    float width;
    float height;


public:
    void decrease_health(float hitpoints)
    {
        health = health - hitpoints;
    }

    void spriteshift(std::string direction){};
    int getx()
    {
        return x_location;
    };
    int gety()
    {
        return y_location;
    };
    void setlocation(int x, int y)
    {
        x_location = x;
        y_location = y;
    };

    People()
    {
        health = 100;
        width = 5;
        height = 10;

        x_location = 0;
        y_location = 0;

    }
};