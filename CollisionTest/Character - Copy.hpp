#include "Master.hpp"
#include "Texture.hpp"

class Character : public MasterObject
{
public:
    Character() {}
    Character(const char *sprite, SDL_Renderer *gRenderer, int x, int y)
    {
        Character::setx(x);
        Character::sety(y);
        Character::setRen(gRenderer);
        Character::setdRect(x, y, 128, 128);
        Character::setTex(texture::sprite(sprite, gRenderer));
    }
    Character(const char *sprite, SDL_Renderer *gRenderer, int x, int y, int Frames, int Speed) : Character(sprite, gRenderer, x, y)
    {
        Character::set_animated();
        Character::setframes(Frames);
        Character::setspeed(Speed);
    }
};
