#include "Master.hpp"
#include "Texture.hpp"
class Terrain : public MasterObject
{
public:
    Terrain(const char *sprite, SDL_Renderer *gRenderer, int x, int y)
    {
        Terrain::setx(x);
        Terrain::sety(y);
        Terrain::setRen(gRenderer);
        Terrain::setdRect(0, 0, 571, 999);
        Terrain::setTex(texture::sprite(sprite, gRenderer));
    }
};