// #include "GameObject.h"
// #include "Game.h"
// #include <cmath>

// class Paper
// {
// private:
//     bool collected;
//     int x;
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

//     Paper()
//     {
//         collected = false;
//     }
//     void papercollected(GameObject *A, Key *B)
//     {
//         if (pow(pow(this->getx() - A->getx(), 2) + pow(this->gety() - A->gety(), 2), 0.5) <= 5)
//         {
//             if (B->getstate())
//             {
//                 collected = true;
//             }
//             else
//             {
//                 std::cout << "you dont have the key to unlock this";
//             }
//         }
//     }
// };