#include "Game.hpp"
SDL_Texture *bg_temp;
SDL_Texture *char_temp;
SDL_Rect s_rect, d_rect3;

bool Game::runcheck()
{
  return is_running;
}
void Game::update()
{
  A->obj_update();
  B->obj_update();
  B->ApproachPlayer(A);
  d_rect3.h = 571;
  d_rect3.w = 999;
  d_rect3.x = 0;
  d_rect3.y = 0;
}

void Game::render()
{
  SDL_RenderClear(grenderer);
  SDL_RenderCopy(grenderer, bg_temp, NULL, &d_rect3);
  A->obj_render();
  B->obj_render();
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
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 999, 571, 0);
  grenderer = SDL_CreateRenderer(window, -1, 0);
  if (grenderer)
  {
    SDL_SetRenderDrawColor(grenderer, 206, 140, 140, 255);
  }
  is_running = true;
  bg_temp = texture::sprite("./Sprites/bg.jpg", grenderer);
  is_running = true;
  SDL_Event e;
<<<<<<< HEAD

  A = new Player("./Sprites/Player.png", grenderer);
  B = new Enemy("./Sprites/Enemy.png", grenderer); //made both classes into popinters so i could render more effeciently
  == == == =
               Player A("./Sprites/Player.png", grenderer);
  Enemy B("./Sprites/Enemy.png", grenderer);

>>>>>>> 96d10069d189c2df569e21196b1711dfe18a5c84
}

Game::~Game() {}