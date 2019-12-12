#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
// #include "Credits.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    SDL_Window *window = nullptr;
    SDL_Surface *windowSurface = nullptr;
    SDL_Surface *image1 = nullptr;
    SDL_Surface *image2 = nullptr;
    SDL_Surface *image3 = nullptr;
    SDL_Surface *image4 = nullptr;
    SDL_Surface *current_img = nullptr;

    //Initialize SDL Video and Audio
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    //Initialize SDL Mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //Load Audio Files
    Mix_Music *backgroundSound = Mix_LoadMUS("bgmusic.mp3");
    Mix_Chunk *Click = Mix_LoadWAV("Click.wav");
    Mix_Chunk *foot1 = Mix_LoadWAV("foot1.wav");
    Mix_Chunk *foot2 = Mix_LoadWAV("foot2.wav");
    Mix_Chunk *shot = Mix_LoadWAV("shot.wav");

    window = SDL_CreateWindow("Maaz is a gOD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    windowSurface = SDL_GetWindowSurface(window);

    image1 = SDL_LoadBMP("MainMenu.bmp");
    image2 = SDL_LoadBMP("LoadingOne.bmp");
    image3 = SDL_LoadBMP("LoadingTwo.bmp");
    image4 = SDL_LoadBMP("LoadingThree.bmp");
    current_img = image1;

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
                    Mix_HaltMusic();
                    //                        current_img=image3;
                    //                        current_img=image4;
                    break;

                case SDLK_F4:
                    Mix_PlayChannel(-1, Click, 0);
                    isRunning = false;
                    break;

                case SDLK_w:
                    Mix_PlayChannel(-1, foot1, 0);
                    break;

                case SDLK_a:
                    Mix_PlayChannel(-1, foot1, 0);
                    break;

                case SDLK_s:
                    Mix_PlayChannel(-1, foot2, 0);
                    break;

                case SDLK_d:
                    Mix_PlayChannel(-1, foot2, 0);
                    break;

                case SDLK_p:
                    Mix_PlayChannel(-1, shot, 0);
                    break;

                case SDLK_BACKSPACE:
                    // Credits.Credit()
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
    Mix_FreeChunk(foot2);
    Mix_FreeChunk(foot1);
    Mix_FreeChunk(shot);

    current_img = image1 = image2 = nullptr;
    window = nullptr;
    Mix_CloseAudio();
    SDL_Quit;
    return 0;
}
