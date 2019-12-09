<<<<<<< HEAD
// #include "Bullet.h"
=======
>>>>>>> parent of d3f32ec... adding the rest

// bool Bullet::getShotFired()
// {
//     return shot_fired;
// }
// void Bullet::setShotFired(bool shot)
// {
//     shot_fired = shot;
// }
// void Bullet::BulletMove()
// {
//     Setloc(getx() + this->x_direction_movement, gety() + this->y_direction_movement);
// };
// Bullet::Bullet()
// {
//     shot_fired = false;
//     std::cout << "Bullet was made" << std::endl;
// };

// Bullet::Bullet(GameObject A, int x, int y, char *sprite)
// { //incorrect formula for now
//     x_direction_movement = (A.getx() - x, A.gety() - y);
//     y_direction_movement = (A.gety() - y, A.gety() - y);
//     this->Obj_Tex = TextureManager::LoadTexture(sprite);
// }
// void Bullet::obj_render(GameObject *p)
// {
//     SDL_RenderCopyEx(Game::renderer, Obj_Tex, nullptr, &this->dRect, 0, nullptr, SDL_FLIP_HORIZONTAL);
// }
// void Bullet::obj_update()
// {
//     if (shot_fired)
//     {
//         dRect.h = 128;
//         dRect.w = 128;
//         dRect.x = this->getx();
//         dRect.y = this->gety();
//         shot_fired = false;
//         move_bullet = true;
//     }

//     if (move_bullet)
//     {
//         BulletMove();
//     }
// }
