#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

class ui_simplified
{
private:
    SDL_Texture *obj_tex;
    SDL_Rect sRect, dRect;
    SDL_Renderer *ren;
    bool starto;

public:
    void obj_update();
    void obj_render();
    bool start_party();
    void handle_event();
};