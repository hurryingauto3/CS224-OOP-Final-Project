#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Texture.h"
#include "Map.h"
// #include "Camera.h"
#include "Background.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Player.h"
#include "UI.h"

#include "key.hpp"
#include "Paper.hpp"
#pragma once

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    bool isRunning;
    bool isGameRunning;
    SDL_Window *window;
    int collides;
    bool keyfound;
    bool paperfound;
    int collision[56];

public:
    static SDL_Renderer *renderer;

    //Constructors and Destructors
    Game();
    ~Game();
    //Member functions
    void paperfind();
    void init(const std::string title, int xpos, int ypos, int width, int height, bool fullscreen);
    //window Creator
    void handleEvents();
    void update();
    void render();
    void clean();                        //Memory management
    bool running() { return isRunning; } //Run check
    bool gamerunning() { return isGameRunning; }
    bool Collision(SDL_Rect a, SDL_Rect b);
    bool TerrainCollide(int x, int y);
    void DoorOpen(int x, int y);
    void makemap(std::string);
    void Keyfind();
    // void MovementAlgo(GameObject *, GameObject *, int arr[8]);
};

#endif