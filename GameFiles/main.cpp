/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
  and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include "Game.hpp"

int main(int argc, char *args[])
{
  Game *Thegame = new Game();
  while (Thegame->is_runningzz())
  {
    Thegame->HandleEvent();
    Thegame->update();
    Thegame->render();
  }

  Thegame->clean();
  return 0;
}
