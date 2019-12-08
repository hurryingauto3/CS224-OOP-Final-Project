#include "Master.hpp"
#include "Texture.hpp"
class Terrain : public MasterObject
{
private:
    bool passable;

public:
    Terrain(const char *sprite, SDL_Renderer *gRenderer, int x, int y)
    {
        Terrain::setx(x);
        Terrain::sety(y);
        Terrain::setRen(gRenderer);
        Terrain::setdRect(0, 0, 128, 128);
        Terrain::setTex(texture::sprite(sprite, gRenderer));
    }
    void setpass(bool a)
    {
        this->passable = a;
    }
};

class Door : public Terrain
{
private:
    bool state_open;

public:
    Door(const char *sprite, SDL_Renderer *gRenderer, int x, int y) : Terrain(sprite, gRenderer, x, y)
    {
        state_open = false;
    };
    void openclose_door()
    {
        if (state_open == false)
        {
            state_open = true;
            this->setpass(true);
        }
        if (state_open == true)
        {
            state_open = false;
            this->setpass(false);
        }
    };
};

class Window : public Terrain
{
private:
    bool status_broken;

public:
    void breakwindow()
    {
        if (status_broken == false)
        {
            status_broken = true;
            this->setpass(true);
        }
    }
    Window(const char *sprite, SDL_Renderer *gRenderer, int x, int y) : Terrain(sprite, gRenderer, x, y)
    {
        status_broken = false;
    }
};

class Wall : public Terrain
{
private:
    bool passable;

public:
    Wall(const char *sprite, SDL_Renderer *gRenderer, int x, int y) : Terrain(sprite, gRenderer, x, y)
    {
        passable = false;
    }
};
