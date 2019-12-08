#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using namespace std;
#include "Game.hpp"

class Mainmenu : public Game
{
private:
    SDL_Surface *windowSurface = nullptr;
    SDL_Surface *image1 = nullptr;
    SDL_Surface *image2 = nullptr;
    SDL_Surface *current_img = nullptr;
    //Initialize SDL Video and Audio
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //Initialize SDL Mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

public:
    Mainmenu()
    {
        //Load Audio Files
        Mix_Music *backgroundSound = Mix_LoadMUS("./MainMenuMedia/bgmusic.mp3");
        Mix_Chunk *Click = Mix_LoadWAV("./MainMenuMedia/Click.wav");
        window = SDL_CreateWindow("Maaz is a gOD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
        windowSurface = SDL_GetWindowSurface(window);
        image1 = SDL_LoadBMP("./MainMenuMedia/MainMenu.bmp");
        image2 = SDL_LoadBMP("./MainMenuMedia/LoadingOne.bmp");
        current_img = image1;
    }

    Mainmenu_EH()
    {
        //Start playing bg music
        Mix_PlayMusic(backgroundSound, -1);
        bool isRunning = true;
        SDL_Event ev;

        while (isRunning)
        {
            while (SDL_PollEvent(&ev) != 0)
            {
                //  if(SDL_Quit == ev.type)
                //    isRunning=false;
                if (ev.type == SDL_KEYDOWN && ev.key.repeat == 0)
                {
                    switch (ev.key.keysym.sym)
                    {
                    case SDLK_RETURN:
                        Mix_PlayChannel(-1, Click, 0);
                        current_img = image2;
                        break;

                    case SDLK_F4:
                        Mix_PlayChannel(-1, Click, 0);
                        isRunning = false;
                        break;
                    }
                }
            }
            SDL_BlitSurface(current_img, NULL, windowSurface, NULL);
            SDL_UpdateWindowSurface(window);
        }

        SDL_FreeSurface(image1);
        SDL_FreeSurface(image2);

        SDL_DestroyWindow(window);
        Mix_FreeMusic(backgroundSound);
        Mix_FreeChunk(Click);

        current_img = image1 = image2 = nullptr;
        window = nullptr;
        Mix_CloseAudio();
        SDL_Quit;
        return 0;
    }
};
