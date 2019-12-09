#pragma once

#include "Game.h"

class Map
{
private:
    SDL_Rect sRect, dRect;

    SDL_Texture *Wall;
    SDL_Texture *Door;
    SDL_Texture *Window;

    int map[20][25];

public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();
};