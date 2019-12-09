// #include "Master.hpp"
// #include "Character.hpp"
// #include <cmath>

// class Bullet : public MasterObject
// {
// private:
//     static int speed;
//     int x_direction_movement;
//     int y_direction_movement;
//     bool shot_fired;
//     bool move_bullet = false;

// public:
//     bool getShotFired()
//     {
//         return shot_fired;
//     }
//     void setShotFired(bool shot)
//     {
//         shot_fired = shot;
//     }
//     void BulletMove()
//     {
//         this->setx(getx() + this->x_direction_movement);
//         this->sety(gety() + this->y_direction_movement);
//     };
//     ~Bullet(){};
//     Bullet(const char *sprite, SDL_Renderer *gRenderer, int x, int y)
//     {

//         Bullet::setx(x);
//         Bullet::sety(y);
//         Bullet::setRen(gRenderer);
//         Bullet::setdRect(x, y, 128, 128);
//         Bullet::setTex(texture::sprite(sprite, gRenderer));
//     }

//     // Bullet(Player A, int x, int y)
//     // { //incorrect formula for now
//     //     x_direction_movement = (A.getx() - x) / pow(pow((A.getx() - x), 2) - pow(A.gety() - y, 2), 0.5);
//     //     y_direction_movement = (A.gety() - y) / pow(pow((A.getx() - x), 2) - pow(A.gety() - y, 2), 0.5);
//     // }
//     void obj_render(Player *p)
//     {
//         SDL_RenderCopyEx(this->getren(), this->getTex(), nullptr, p->angle(), nullptr, SDL_FLIP_HORIZONTAL);
//     }

//     void obj_update()
//     {
//         if (shot_fired)
//         {
//             Bullet::setdRect(this->getx(), this->gety(), 128, 128);
//             shot_fired = false;
//             move_bullet = true;
//         }

//         if (move_bullet)
//         {
//             Bullet::setdRect(this->getx() + 7, this->gety(), 128, 128);
//         }
//     }
// };
