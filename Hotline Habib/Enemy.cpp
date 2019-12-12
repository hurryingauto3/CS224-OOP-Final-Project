// #include "Enemy.h"

// bool Enemyy::IsPlayerClose(Playerr *A)
// {
//     if (pow(pow(this->getx() - A->getx(), 2) + pow(this->gety() - A->gety(), 2), 0.5) < 200)
//     {
//         this->IsPlayerClosebool = true;
//         return true;
//     }
//     else
//     {
//         this->IsPlayerClosebool = false;
//         return false;
//     }
// }

// void Enemyy::ApproachPlayer(Playerr *A)
// {
//     if (this->getx() != A->getx() | this->gety() != A->gety())
//     {
//         if (this->getx() > A->getx())
//         {
//             this->Setloc(this->getx() - 1, this->gety());
//         }
//         if (this->getx() < A->getx())
//         {
//             this->Setloc(this->getx() + 1, this->gety());
//         }
//         if (this->gety() > A->gety())
//             this->Setloc(this->getx(), this->gety() - 1);
//     }
//     if (this->gety() < A->gety())
//     {
//         this->Setloc(this->getx(), this->gety() + 1);
//     }
// }

// bool Enemyy::returnclose()
// {

//     return this->IsPlayerClosebool;
// }

// void Enemyy::Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
// {
//     if (this->gety() == y1 && this->getx() != x2)
//     {
//         this->Setloc(this->getx() + 1, this->gety());
//         this->Update();
//     }
//     else if (this->getx() == x2 && this->gety() != y3)
//     {
//         this->Setloc(this->getx(), this->gety() + 1);
//         this->Update();
//     }
//     else if (this->gety() == y3 && this->getx() != x1)
//     {
//         this->Setloc(this->getx() - 1, this->gety());
//         this->Update();
//     }
//     else if (this->getx() == x1 && this->gety() != y1)
//     {
//         this->Setloc(this->getx(), this->gety() - 1);
//         this->Update();
//     }
// }
// Enemyy::Enemyy(std::string Sprite, int xpos, int ypos) : GameObject(Sprite, xpos, ypos)
// {
//     this->IsPlayerClosebool = false;
// }
// Enemyy::Enemyy(std::string Sprite, int xpos, int ypos, int frames, int speed) : GameObject(Sprite, xpos, ypos, frames, speed)
// {
//     this->IsPlayerClosebool = false;
// }
