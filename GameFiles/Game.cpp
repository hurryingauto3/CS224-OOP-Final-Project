#include "Game.hpp"

bool Game::runcheck()
{
  return is_running;
}
void Game::update()
{
  A->obj_update();
  B->obj_update();

  B->IsPlayerClose(*A);
  if (B->getplayercloseby())
  {
    B->ApproachPlayer(*A);
    B->obj_update();
  }
  else
  {
    B->Path(0, 0, 100, 0, 100, 100, 0, 100);
    B->obj_update();
  }

  C->obj_update();
}

void Game::render()
{
  SDL_RenderClear(grenderer);
  C->obj_render();
  A->obj_render();

  Obj->RenderAll();

  SDL_RenderPresent(grenderer);
}
void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(grenderer);
  SDL_Quit();
}
void Game::handle_event()
{
  SDL_Event Event;
  SDL_PollEvent(&Event);
  switch (Event.type)
  {
  case SDL_QUIT:
    is_running = false;

  case SDL_KEYDOWN: //both classes are pointers now so used arrows
    switch (Event.key.keysym.sym)
    {
    case SDLK_s:
      A->setlocation(A->getx(), A->gety() + 5);
      break;
    case SDLK_d:
      A->setlocation(A->getx() + 5, A->gety());
      break;
    case SDLK_a:
      A->setlocation(A->getx() - 5, A->gety());
      break;
    case SDLK_w:
      A->setlocation(A->getx(), A->gety() - 5);
      break;
    case SDLK_p:
      A->shoot();
      break;
    default:
      break;
    }
  default:
    break;
  }
}
Game::Game()
{
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, 0);
  grenderer = SDL_CreateRenderer(window, -1, 0);
  if (grenderer)
  {
    SDL_SetRenderDrawColor(grenderer, 206, 140, 140, 255);
  }
  is_running = true;

  SDL_Event e;
  Obj->addnode(new Enemy("./Sprites/Enemy.png", grenderer, 10, 10));
  Obj->addnode(new Enemy("./Sprites/Enemy.png", grenderer, 300, 300));
  Obj->addnode(new Enemy("./Sprites/Enemy.png", grenderer, 50, 50));

  A = new Player("./Sprites/Player.png", grenderer);
  //made both classes into popinters so i could render more effeciently
  C = new BG("./Sprites/level_BG.png", grenderer);
}

Game::~Game() {}