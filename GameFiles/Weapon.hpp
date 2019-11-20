class Weapon
{
private:
    float attackpwr;
    float decay_rate;
    int rpm;
    int magsize;
    float reload_time;
    char type;

public:
    char virtual weapontype()
    {
        char x = '0';
        return x;
    }
    void virtual attack() {}
    int virtual bullets_left() {}
    void virtual attack_decay() {}
    void virtual reload() {}
    void
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
