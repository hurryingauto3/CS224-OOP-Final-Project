// #include <iostream>
// #include <cmath>

// #pragma once

// class Player : public GameObject
// {
// private:
//     SDL_Texture *obj_tex;
//     SDL_Rect sRect, dRect, camera;
//     int a = 3;

// public:
//     void shoot()
//     {
//         std::cout << "Shot fired" << std::endl;
//     };

//     Player(){};

//     int getSpeed()
//     {
//         return a;
//     }

//     Player(std::string sprite, SDL_Renderer *gRenderer, int x, int y)
//     {
//         Player::Setloc(x, y);
//         obj_tex = TextureManager::LoadTexture(sprite);
//         dRect.h = 128;
//         dRect.w = 128;
//         dRect.x = this->getx();
//         dRect.y = this->gety();
//         camera = {this->getx(), this->gety(), 1080, 720};

//         SDL_RenderCopy(Game::renderer, obj_tex, nullptr, &dRect);
//     }

//     void obj_update()
//     {

//         dRect.h = 128;
//         dRect.w = 128;
//         dRect.x = getx();
//         dRect.y = gety();

//         angle();

//         // camera.x = getx() - 540;
//         // camera.y = gety() - 360;

//         // if (camera.x < 0)
//         // {
//         //     camera.x = 0;
//         // }
//         // if (camera.y < 0)
//         // {
//         //     camera.y = 0;
//         // }
//         // if (camera.x + camera.w >= 1800)
//         // {
//         //     camera.x = 1800 - camera.w;
//         // }
//         // if (camera.y + camera.h >= 1300)
//         // {
//         //     camera.y = 1300 - camera.h;
//         // }
//     }

//     void obj_render()
//     {
//         dRect = {dRect.x - camera.x, dRect.y - camera.y, dRect.w, dRect.h};
//         SDL_RenderCopyEx(Game::renderer, obj_tex, nullptr, &dRect, angle(), nullptr, SDL_FLIP_HORIZONTAL); //sRect is null for now
//     }
//     double angle()
//     {
//         int x, y;
//         SDL_GetMouseState(&x, &y);
//         int a = x;
//         int b = y;
//         int base = getx() - a;
//         int height = gety() - b;
//         double ans = atan2(height, base) * 180 / 3.14159265;
//         return ans;
//     }
// };
