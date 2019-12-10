// #include "Enemy.hpp"

// Enemy::Enemy()
// {
//     Enemy::PlayernearBy = false;
// };

// Enemy::Enemy(const char *sprite, SDL_Renderer *r, int x, int y) : Enemy()
// {
//     Enemy::setlocation(x, y);
//     std::cout << "Enemy born" << std::endl;
// }

// Enemy::Enemy(const char *sprite, SDL_Renderer *r)
// {
//     Enemy::setlocation(0, 0);

//     ren = r;
//     obj_tex = texture::sprite(sprite, r);
// }
// void Enemy::obj_update()
// {
//     sRect.h = 208;
//     sRect.w = 208;
//     sRect.x = 0;
//     sRect.y = 0;
//     dRect.h = 128;
//     dRect.w = 128;
//     dRect.x = getx();
//     dRect.y = gety();
// }

// // Enemy::Enemy(const char *sprite, SDL_Renderer *r, int x, int y, float health) : Enemy(sprite, r, x, y) //we don't need these anymore
// // {
// //     Enemy::sethealth(health);
// // }

// // Enemy::Enemy(const char *sprite, SDL_Renderer *r, int x, int y, float health, float attack) : Enemy(sprite, r, x, y, health)
// // {
// //     Enemy::setattack(attack);
// // }

// void Enemy::obj_render(Player *p)
// {
//     SDL_RenderCopyEx(ren, obj_tex, nullptr, &dRect, angle(p), nullptr, SDL_FLIP_HORIZONTAL);
// }
// void Enemy::Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
// {
//     if (this->gety() == y1 && this->getx() != x2)
//     {
//         this->setlocation(this->getx() + 1, this->gety());
//         this->obj_update();
//     }
//     else if (this->getx() == x2 && this->gety() != y3)
//     {
//         this->setlocation(this->getx(), this->gety() + 1);
//         this->obj_update();
//     }
//     else if (this->gety() == y3 && this->getx() != x1)
//     {
//         this->setlocation(this->getx() - 1, this->gety());
//         this->obj_update();
//     }
//     else if (this->getx() == x1 && this->gety() != y1)
//     {
//         this->setlocation(this->getx(), this->gety() - 1);
//         this->obj_update();
//     }
// }

// void Enemy::IsPlayerClose(GameObject *A)
// {
//     if (pow(pow(this->getx() - A->getx(), 2) + pow(this->gety() - A->gety(), 2), 0.5) < 200)
//     {
//         Enemy::PlayernearBy = true;
//     }
//     else
//     {
//         Enemy::PlayernearBy = false;
//     }
// }

// void Enemy::ApproachPlayer(Player *A)
// {
//     if (this->getx() != A->getx() | this->gety() != A->gety())
//     {
//         if (this->getx() > A->getx())
//         {
//             this->setlocation(this->getx() - 1, this->gety());
//         }
//         if (this->getx() < A->getx())
//         {
//             this->setlocation(this->getx() + 1, this->gety());
//         }
//         if (this->gety() > A->gety())
//             this->setlocation(this->getx(), this->gety() - 1);
//     }
//     if (this->gety() < A->gety())
//     {
//         this->setlocation(this->getx(), this->gety() + 1);
//     }
// }

// double Enemy::angle(Player *p)
// {
//     int base = p->getx() - getx();
//     int height = p->gety() - gety();
//     double ans = atan2(height, base) * 180 / 3.14159265;
//     return ans;
// }

// bool Enemy::getplayercloseby()
// {
//     return Enemy::PlayernearBy;
// }