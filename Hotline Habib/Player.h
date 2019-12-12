// #include <iostream>
// #include <cmath>
// #include "GameObject.h"

// #ifndef PLAYER_H
// #define PLAYER_H

// class Player : public GameObject
// {
// private:
//     static Player *player;
//     int data;

//     Player(std::string Sprite, int xpos, int ypos) : GameObject(Sprite, xpos, ypos)
//     {
//         data = 0;
//     }

//     Player(std::string Sprite, int xpos, int ypos, int frames, int speed) : GameObject(Sprite, xpos, ypos, frames, speed)
//     {
//         data = 0;
//     }

// public:
//     static Player *getPlayer(std::string Sprite, int xpos, int ypos)
//     {
//         if (player == nullptr)
//         {
//             player = new Player(Sprite, xpos, ypos);
//         }
//         return player;
//     }

//     static Player *getPlayer(std::string Sprite, int xpor, int ypos, int frames, int speed)
//     {
//         if (player == nullptr)
//         {
//             player = new Player(Sprite, xpor, ypos, frames, speed);
//         }
//         return player;
//     }

//     int getData()
//     {
//         return this->data;
//     }

//     void setData(int x)
//     {
//         this->data = x;
//     }
// };

// #endif

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

//
//         angle();

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
