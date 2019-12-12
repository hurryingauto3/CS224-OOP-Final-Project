#include "GameObject.h"
#include "Game.h"

class Key : public GameObject
{
private:
    bool collected;

public:
    Key()
    {
        collected = false;
    }
    void keycollected(GameObject *A)
    {
        if (pow(pow(this->getx() - A->getx(), 2) + pow(this->gety() - A->gety(), 2), 0.5) <= 5)
        {
            collected = true;
        }
    }
};