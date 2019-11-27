#include "Weapon.hpp"

int Weapon::getx()
{
    return this->xloc;
}
int Weapon::gety()
{
    return this->yloc;
}
void Weapon::setdecayrate(float decrate)
{
    this->decay_rate = decrate;
}
void Weapon::setattackpwr(float attack)
{
    this->attackpwr = attack;
}
float Weapon::attackpwr()
{
    return this->attackpwr;
}
void Weapon::maploc(int x, int y)
{
    this->xloc = x;
    this->yloc = y;
}
void Weapon::setweapontype(char type)
{
    this->type = type;
}
char Weapon::weapontype()
{
    return this->type;
}
void Weapon::fire()
{
    this->bulletsfired++;
}
int Weapon::bullets_left()
{
    return this->magsize - this->bulletsfired;
}
float Weapon::attackpower_decayed(Player A, Enemy B)
{
    float tempattackpwr;
    tempattackpwr = this->attackpwr - sqrt(pow((A.gety() - B.gety()), 2) + pow((A.getx() - B.getx()), 2)) * this->decay_rate;
    return tempattackpwr;
}
void Weapon::reload() {}
void Weapon::setmagsize(int mag)
{
    this->magsize = mag;
}
int Weapon::magsize()
{
    return this->magsize;
}
void Weapon::pickgunup(Player A)
{
    if (abs((A.gety() - this->gety()) < 5 | abs(A.getx() - this->getx()) < 5) | sqrt(pow((A.gety() - A.gety()), 2) + pow((A.getx() - A.getx()), 2)) < 5)
    {
        this->gunpicked = true;
    }
}
bool Weapon::gunpicked() { return this->gunpicked; }
