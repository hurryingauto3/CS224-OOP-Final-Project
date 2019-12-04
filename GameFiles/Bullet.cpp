#include "Master.hpp"
#include "Player.hpp"
#include <cmath>

class Bullet : public MasterObject
{
private:
    static int speed;
    int x_direction_movement;
    int y_direction_movement;

public:
    void BulletMove()
    {
        setlocation(getx() + this->x_direction_movement, gety() + this->y_direction_movement);
    };
    Bullet()
    {
        std::cout << "Bullet was made" << std::endl;
    };

    Bullet(Player A, int x, int y)
    { //incorrect formula for now
        x_direction_movement = (A.getx() - x) / pow(pow((A.getx() - x), 2) - pow(A.gety() - y, 2), 0.5);
        y_direction_movement = (A.gety() - y) / pow(pow((A.getx() - x), 2) - pow(A.gety() - y, 2), 0.5);
    }
};