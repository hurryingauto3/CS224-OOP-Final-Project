
#include "Texture.hpp"
#include <cmath>
#include "Player.hpp"
#pragma once
class Enemy : public People
{

private:
    bool PlayernearBy;
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;

public:
    Enemy();

    Enemy(const char *sprite, SDL_Renderer *r, int x, int y);

    Enemy(const char *sprite, SDL_Renderer *r);

    void obj_update(Player *p);
    // Enemy(const char *sprite, SDL_Renderer *r, int x, int y, float health); //we don't need these anymore
    // Enemy(const char *sprite, SDL_Renderer *r, int x, int y, float health, float attack);
    void obj_update();
    void obj_render(Player *p);
    void Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    bool getplayercloseby();
    void IsPlayerClose(Player *A);
    void ApproachPlayer(Player *A);
    double angle(Player *p);
};