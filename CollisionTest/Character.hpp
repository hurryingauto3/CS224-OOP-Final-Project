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
        Character::setdRect(0, 0, 128, 128);
        Character::setTex(texture::sprite(sprite, gRenderer));
    }
};
