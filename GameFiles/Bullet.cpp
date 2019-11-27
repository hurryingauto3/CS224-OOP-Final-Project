#include "Master.hpp"
#include "Player.hpp"

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
        x_direction_movement = (A.getx() - x);
        y_direction_movement = (A.gety() - y);
    };
};