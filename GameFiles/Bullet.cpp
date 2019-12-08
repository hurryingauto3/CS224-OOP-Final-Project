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
    int x;
    int y;
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
    ~Bullet(){};
    Bullet(const char *sprite, SDL_Renderer *gRenderer)
    {
        //Player::setlocation(200, 200);
        ren = gRenderer;
        obj_tex = texture::sprite(sprite, gRenderer);
    }

    // Bullet(Player A, int x, int y)
    // { //incorrect formula for now
    //     x_direction_movement = (A.getx() - x) / pow(pow((A.getx() - x), 2) - pow(A.gety() - y, 2), 0.5);
    //     y_direction_movement = (A.gety() - y) / pow(pow((A.getx() - x), 2) - pow(A.gety() - y, 2), 0.5);
    // }
    void obj_render(Player *p)
    {
        SDL_RenderCopyEx(ren, obj_tex, nullptr, &dRect, p->angle(), nullptr, SDL_FLIP_HORIZONTAL);
    }
    void obj_update()
    {
        if (shot_fired)
        {
            dRect.h = 128;
            dRect.w = 128;
            dRect.x = x;
            dRect.y = y;
            shot_fired = false;
            move_bullet = true;
        }

        if (move_bullet)
        {
            dRect.x += 7;
        }
    }

    void setX(int X)
    {
        x = X;
    }
    void setY(int Y)
    {
        y = Y;
    }
};
