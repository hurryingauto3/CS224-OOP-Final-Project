// #include "GameObject.h"
// #include "Game.h"
// #include <cmath>

// class Key
// {
// private:
//     int x;
//     bool collected;
//     int y;

// public:
//     int getx()
//     {
//         return x;
//     }
//     int gety()
//     {
//         return y;
//     }
//     Key()
//     {
//         collected = false;
//     }
//     bool getstate()
//     {
//         return collected;
//     }
//     void keycollected(GameObject *A)
//     {
//         if (pow(pow(this->getx() - A->getx(), 2) + pow(this->gety() - A->gety(), 2), 0.5) <= 5)
//         {
//             collected = true;
//         }
//     }
// };