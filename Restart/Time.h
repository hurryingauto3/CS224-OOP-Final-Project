#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

int main(int argc, char **argv)
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window *window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface *surface;
    SDL_Texture *texture;

    int score = 0;
    char buffer[9999];
    int texW = 0;
    int texH = 0;
    TTF_Font *font = TTF_OpenFont("dr.ttf", 25);
    SDL_Color color = {255, 255, 255};

    while (!quit)

    {
        SDL_RenderClear(renderer);

        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

        score += 1;
        sprintf(buffer, "Survived: %d seconds", score / 100);

        surface = TTF_RenderText_Solid(font, buffer, color);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

        SDL_FreeSurface(surface);
        SDL_Rect dstrect = {0, 0, texW, texH};
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

    TTF_Quit();
    SDL_Quit();

    return 0;
}
