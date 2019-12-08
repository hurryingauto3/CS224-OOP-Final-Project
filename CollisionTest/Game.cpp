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
    allobjs.push_back(new Character("./Sprites/Player.png", grenderer, 0, 100));
    moving.push_back(new Character("./Sprites/Player.png", grenderer, 100, 500));
    moving.push_back(new Character("./Sprites/Player.png", grenderer, 600, 500));
}

bool Game::RunCheck()
{
    return this->is_running;
}

void Game::render()
{

    SDL_RenderClear(grenderer);
    for (int i = 0; i <= allobjs.size() - 1; i++)
    {
        allobjs[i]->obj_render(allobjs[i]->getren(), allobjs[i]->getTex(), allobjs[i]->getsrekt(), allobjs[i]->getdrekt());
    }
    for (int i = 0; i <= moving.size() - 1; i++)
    {
        moving[i]->obj_render(moving[i]->getren(), moving[i]->getTex(), moving[i]->getsrekt(), moving[i]->getdrekt());
        SDL_RenderPresent(grenderer);
    }
}

void Game::update()
{
    for (int i = 0; i <= allobjs.size() - 1; i++)
    {
        allobjs[i]->obj_update();
    }
    for (int i = 0; i <= moving.size() - 1; i++)
    {
        moving[i]->obj_update();
    }
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

    case SDL_KEYDOWN:

    {
        switch (event.key.keysym.sym)
        {

        case SDLK_s:
            for (int i = 0; i <= allobjs.size() - 1; i++)
            {
                for (int j = 0; j <= moving.size() - 1; j++)
                    if (!collision(allobjs[i]->getdrekt(), moving[j]->getdrekt()))
                    {
                        allobjs[i]->setx(allobjs[i]->getx()), allobjs[i]->sety(allobjs[i]->gety() + 5);
                        std::cout << "S Pressed: " << allobjs[i]->gety() << std::endl;
                    }
                    else
                    {
                        allobjs[i]->setx(allobjs[i]->getx()), allobjs[i]->sety(allobjs[i]->gety() - 20);
                    }
            }
            break;
        case SDLK_d:
            for (int i = 0; i <= allobjs.size() - 1; i++)
            {
                for (int j = 0; j <= moving.size() - 1; j++)
                    if (!collision(allobjs[i]->getdrekt(), moving[j]->getdrekt()))
                    {
                        allobjs[i]->setx(allobjs[i]->getx() + 5), allobjs[i]->sety(allobjs[i]->gety());
                        std::cout << "D Pressed: " << allobjs[i]->getx() << std::endl;
                    }
                    else
                    {
                        allobjs[i]->setx(allobjs[i]->getx() - 20), allobjs[i]->sety(allobjs[i]->gety());
                    }
            }
            break;

        case SDLK_a:
            for (int i = 0; i <= allobjs.size() - 1; i++)
            {
                for (int j = 0; j <= moving.size() - 1; j++)
                    if (!collision(allobjs[i]->getdrekt(), moving[j]->getdrekt()))
                    {
                        allobjs[i]->setx(allobjs[i]->getx() - 5), allobjs[i]->sety(allobjs[i]->gety());
                        std::cout << "D Pressed: " << allobjs[i]->getx() << std::endl;
                    }
                    else
                    {
                        allobjs[i]->setx(allobjs[i]->getx() + 20), allobjs[i]->sety(allobjs[i]->gety());
                    }
            }
            break;
        case SDLK_w:
            for (int i = 0; i <= allobjs.size() - 1; i++)
            {
                for (int j = 0; j <= moving.size() - 1; j++)
                {
                    if (!collision(allobjs[i]->getdrekt(), moving[j]->getdrekt()))
                    {
                        allobjs[i]->setx(allobjs[i]->getx()), allobjs[i]->sety(allobjs[i]->gety() - 5);
                        std::cout << "W Pressed: " << allobjs[i]->gety() << std::endl;
                    }
                    else
                    {
                        allobjs[i]->setx(allobjs[i]->getx()), allobjs[i]->sety(allobjs[i]->gety() + 20);
                    }
                }
            }
            break;
        }
    }
    }
}
