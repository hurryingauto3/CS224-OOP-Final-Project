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

#include "Enemy.hpp"
#include "Player.hpp"
#include "Terrain.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void closer();

SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;
SDL_Surface *hi = NULL;

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    hi = SDL_LoadBMP("D:/CS224-OOP-Final-Project/Sprites/Terrain.bmp");
    if (hi == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "D:/CS224-OOP-Final-Project/Sprites/Terrain.bmp", SDL_GetError());
        success = false;
    }
    return success;
}

void closer()
{
    SDL_FreeSurface(hi);
    hi = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}

int main(int argc, char *args[])
{
    if (!init())
    {
        printf("Couldnt be initialized! \n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load image! \n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;

            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                SDL_BlitSurface(hi, NULL, screenSurface, NULL);
                SDL_UpdateWindowSurface(window);
            }
            //SDL_Delay(2000);
        }
    }
    closer();
    return 0;
}