#include "Game.hpp"

Game::Game()
{

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, 0);
    grenderer = SDL_CreateRenderer(window, -1, 0);
    if (grenderer)
    {
        SDL_SetRenderDrawColor(grenderer, 206, 140, 140, 255);
        std::cout << "Rendered" << std::endl;
    }
    is_running = true;
    SDL_Event e;
    A = new Character("./Sprites/Player.png", grenderer, 0, 100);
    B = new Character("./Sprites/Player.png", grenderer, 100, 500);
}
bool Game::RunCheck()
{
    return this->is_running;
}

void Game::render()
{
    SDL_RenderClear(grenderer);
    A->obj_render(A->getren(), A->getTex(), A->getsrekt(), A->getdrekt());
    A->obj_render(B->getren(), B->getTex(), B->getsrekt(), B->getdrekt());
    SDL_RenderPresent(grenderer);
}

void Game::update()
{
    A->obj_update();
    B->obj_update();
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(grenderer);
    SDL_Quit();
}
void Game::handle_event()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;

    case SDL_KEYDOWN: //both classes are pointers now so used arrows
        switch (event.key.keysym.sym)
        {
        case SDLK_s:
            A->setx(A->getx()), A->sety(A->gety() + 5);
            break;
        case SDLK_d:
            A->setx(A->getx() + 5), A->sety(A->gety());
            break;
        case SDLK_a:
            A->setx(A->getx() - 5), A->sety(A->gety());
            break;
        case SDLK_w:
            A->setx(A->getx()), A->sety(A->gety() - 5);
            break;

        case SDLK_k:
            B->setx(B->getx()), B->sety(B->gety() + 5);
            break;
        case SDLK_l:
            B->setx(B->getx() + 5), B->sety(B->gety());
            break;
        case SDLK_i:
            B->setx(B->getx()), B->sety(B->gety() - 5);
            break;
        case SDLK_j:
            B->setx(B->getx() - 5), B->sety(B->gety());
            break;
        default:
            break;
        }
    }
}
