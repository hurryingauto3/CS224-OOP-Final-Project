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
    B[0] = new Character("./Sprites/Player.png", grenderer, 100, 500);
}
bool Game::RunCheck()
{
    return this->is_running;
}

void Game::render()
{
    SDL_RenderClear(grenderer);
    A->obj_render(A->getren(), A->getTex(), A->getsrekt(), A->getdrekt());
    B[0]->obj_render(B[0]->getren(), B[0]->getTex(), B[0]->getsrekt(), B[0]->getdrekt());
    SDL_RenderPresent(grenderer);
}

void Game::update()
{
    A->obj_update();
    B[0]->obj_update();
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
            B[0]->setx(B[0]->getx()), B[0]->sety(B[0]->gety() + 5);
            break;
        case SDLK_l:
            B[0]->setx(B[0]->getx() + 5), B[0]->sety(B[0]->gety());
            break;
        case SDLK_i:
            B[0]->setx(B[0]->getx()), B[0]->sety(B[0]->gety() - 5);
            break;
        case SDLK_j:
            B[0]->setx(B[0]->getx() - 5), B[0]->sety(B[0]->gety());
            break;
        default:
            break;
        }
    }
}