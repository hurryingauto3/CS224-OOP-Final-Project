#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Texture.h"
#include "GameObject.h"
#include "Map.h"
#include "Camera.h"
#include "Background.h"
#include "Bullet.h"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    bool KeyFound;
    bool PaperFound;
    bool Door1;
    bool Door2;
    bool Door3;
public:
    static SDL_Renderer *renderer;

    //Constructors and Destructors
    Game();
    ~Game();

    //Member functions
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen); //window Creator
    void handleEvents();
    void update();
    void render();
    void clean();   //Memory management
    bool running(); //Run check
    bool collision(SDL_Rect a, SDL_Rect b);
    bool TerrainCollide(int x, int y, bool door1, bool door2, bool door3);
    void DoorOpen(int x, int y);
};

#endif
