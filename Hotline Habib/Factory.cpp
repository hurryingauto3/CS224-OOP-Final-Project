#include "GameObject.h"
class Factory
{
    int enemies;

public:
    Factory()
    {
        enemies = 0;
    }

    GameObject make(std::string type)
    {
        if (type == "player")
        {
            return GameObject("./Sprites/Player/player_stat.png", 970, 70, 2, 150);
        }
        if (type == "enemy")
        {
            if (enemies == 0)
            {
                return GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 60, 2, 150);
                enemies++;
            }
            if (enemies == 1)
            {
                return GameObject("./Sprites/Enemy/Enemy_updown.png", 700, 60, 2, 150);
                enemies++;
            }
            if (enemies == 2)
            {
                return GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 510, 2, 150);
                enemies++;
            }
        }
    }
};