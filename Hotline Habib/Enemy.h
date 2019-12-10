#include "GameObject.h"

#ifndef ENEMY_H
#define ENEMY_H
class Enemy : virtual public GameObject
{
private:
    bool IsPlayerClosebool;

public:
    bool IsPlayerClose(GameObject *A);
    void ApproachPlayer(GameObject *A);
    bool returnclose();
    void Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    Enemy() {}
    Enemy(std::string Sprite, int xpos, int ypos);
    Enemy(std::string Sprite, int xpos, int ypos, int frames, int speed);
    ~Enemy();
};

#endif
