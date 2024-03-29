#include "Master.hpp"
#include "Player.hpp"
#include <cmath>

class Bullet : public MasterObject
{
private:
    static int speed;
    int x_direction_movement;
    int y_direction_movement;
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    bool shot_fired;
    bool move_bullet = false;

public:
    bool getShotFired()
    {
        return shot_fired;
    }
    void setShotFired(bool shot)
    {
        shot_fired = shot;
    }
    void BulletMove()
    {
        setlocation(getx() + this->x_direction_movement, gety() + this->y_direction_movement);
    };
    Bullet()
    {
        shot_fired = false;
        std::cout << "Bullet was made" << std::endl;
    };

    Bullet(Player A, int x, int y, const char *sprite, SDL_Renderer *gRenderer)
    { //incorrect formula for now
        x_direction_movement = (A.getx() - x, A.gety() - y);
        y_direction_movement = (A.gety() - y, A.gety() - y);
        ren = gRenderer;
        obj_tex = texture::sprite(sprite, gRenderer);
    }
    void obj_render(Player *p)
    {
        SDL_RenderCopyEx(ren, obj_tex, nullptr, &dRect, 0, nullptr, SDL_FLIP_HORIZONTAL);
    }
    void obj_update()
    {
        if (shot_fired)
        {
            dRect.h = 128;
            dRect.w = 128;
            dRect.x = this->getx();
            dRect.y = this->gety();
            shot_fired = false;
            move_bullet = true;
        }

        if (move_bullet)
        {
            BulletMove();
        }
    }
};
