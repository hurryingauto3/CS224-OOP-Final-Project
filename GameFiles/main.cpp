
#include "Enemy.hpp"
#include "Player.hpp"
#include "Terrain.hpp"

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

Uint32 framestart;
int frametime;

const int fps = 60;
const int framedelay = 1000 / fps;

int main(int argc, char *args[])
{
  std::cout << "Started" << std::endl;
  Game Thegame;
  std::cout << "Game Object Created" << std::endl;
  Wall B;
  while (Thegame.runcheck())
  {

    framestart = SDL_GetTicks();
    Thegame.handle_event();
    Thegame.update();
    Thegame.render();
    frametime = SDL_GetTicks() - framestart;
    if (framedelay > frametime)
    {
      SDL_Delay(framedelay - frametime);
    }
  }

  Thegame.clean();
  return 0;
}

