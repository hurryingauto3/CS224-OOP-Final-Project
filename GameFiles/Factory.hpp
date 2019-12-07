#include "Master.hpp"
#include "Enemy.hpp"
#include "Bullet.cpp"
#include "Terrain.hpp"

class Factory
{
public:
    static MasterObject *createMaster(int type)
    {
        switch (type)
        {
        case (1):
            return new Wall;
            break;
        case (2):
            return new Enemy;
            break;
        case (3):
            return new Bullet;
            break;
        case (4):
            return new Door;
            break;
        case (5):
            return new Window;
            break;
        default:
            break;
        }
    }
};
