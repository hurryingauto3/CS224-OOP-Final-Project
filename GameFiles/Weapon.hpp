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
    int getx() { return this->xloc; }
    int gety() { return this->yloc; }
    void setdecayrate(float decrate) { this->decay_rate = decrate; }
    void setattackpwr(float attack) { this->attackpwr = attack; }
    float attackpwr() { return this->attackpwr; }
    void maploc(int x, int y)
    {
        this->xloc = x;
        this->yloc = y;
    }
    void setweapontype(char type) { this->type = type; }
    char weapontype() { return this->type; }
    void fire()
    {
        this->bulletsfired++;
    }
    int bullets_left()
    {   
        return this->magsize - this->bulletsfired;
    }
    float attackpower_decayed(Player A, Enemy B)
    {
        float tempattackpwr;
        tempattackpwr = this->attackpwr - sqrt(pow((A.gety() - B.gety()), 2) + pow((A.getx() - B.getx()), 2)) * this->decay_rate;
        return tempattackpwr;
    }
    void reload() {}
    void setmagsize(int mag) { this->magsize = mag; }
    int magsize() { return this->magsize; }
    void pickgunup(Player A)
    {
        if (abs((A.gety() - this->gety()) < 5 | abs(A.getx() - this->getx()) < 5))
        {
            gunpicked = true;
        }
    }
    bool gunpicked() { return this->gunpicked; }
};

class gun : public Weapon
{
private:
public:
    gun()
    {
        gun::setattackpwr(3.5);
        gun::maploc(25, 25);
    }
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
