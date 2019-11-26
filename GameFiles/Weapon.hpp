<<<<<<< Updated upstream
class Weapon
{
=======
#include "Enemy.hpp"
#include <cmath>
class Weapon
{
private:
    float attackpwr;
    float decay_rate;
    int rpm;
    int magsize;
    float reload_time;
    char type;
    bool gunpicked;
    int xloc;
    int yloc;
    int bulletsfired;
    float width;
    float height;

public:
    int getx();
    int gety();
    void setdecayrate(float decrate);
    void setattackpwr(float attack);
    float attackpwr();
    void maploc(int x, int y);
    void setweapontype(char type);
    char weapontype();
    void fire();
    int bullets_left();
    float attackpower_decayed(Player A, Enemy B);
    void reload() {}
    void setmagsize(int mag);
    int magsize();
    void pickgunup(Player A);
    bool gunpicked();
>>>>>>> Stashed changes
};

class gun : public Weapon
{
private:
public:
};

class minigun : public Weapon
{
private:
public:
};

class BaseBallBat : public Weapon
{
private:
public:
};
