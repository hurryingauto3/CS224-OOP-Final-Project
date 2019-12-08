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
#include "Background.hpp"
#include "LinkedList.hpp"
#include "Terrain.hpp"
#include "UI.hpp"
#include "Bullet.cpp"
#include <SDL_mixer.h>
#pragma once

class Game
{
private:
    bool is_running;

    LinkedList *Obj;
    Player *A;
    Enemy *B;
    Wall *W;
    BG *C;
    SDL_Window *window;
    SDL_Renderer *grenderer;
    ui_simplified *ui;
    bool onSplashScreen;
    Bullet *bullet;
    Mix_Music *backgroundSound = Mix_LoadMUS("bgmusic.mp3");
    Mix_Chunk *Click = Mix_LoadWAV("Click.wav");
    Mix_Chunk *foot1 = Mix_LoadWAV("foot1.wav");
    Mix_Chunk *foot2 = Mix_LoadWAV("foot2.wav");
    Mix_Chunk *shot = Mix_LoadWAV("shot.wav");
    //bool moving;

public:
    //Initialize SDL Video and Audio
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //Initialize SDL Mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    bool runcheck(); //Returns the status of the game
    void update();
    void render();
    void clean(); //Frees all resources upon quitting
    void handle_event();
    void mousePress(SDL_MouseButtonEvent &b);
    SDL_Rect camera;
    Game();
    ~Game();

    bool collision(SDL_Rect a, SDL_Rect b)
    {
        if (a.y >= b.y + b.h)
        {
            return false;
        }
        if (a.x >= b.x + b.w)
        {
            return false;
        }
        if (a.y + a.h <= b.y)
        {
            return false;
        }
        if (a.x + a.w <= b.x)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
