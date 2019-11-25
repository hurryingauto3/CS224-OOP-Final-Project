#include "Game.hpp"
SDL_Texture *bg_temp;
SDL_Rect s_rect, d_rect3;

bool Game::runcheck()
{
  return is_running;
}
void Game::update()
{

  A->update();
  d_rect3.h = 571;
  d_rect3.w = 999;
  d_rect3.x = 0;
  d_rect3.y = 0;
  B.ApproachPlayer(A);
}

void Game::render()
{
  SDL_RenderClear(grenderer);
  SDL_RenderCopy(grenderer, bg_temp, NULL, &d_rect3);

  A->render();
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

  case SDL_KEYDOWN:
    switch (Event.key.keysym.sym)
    {
    case SDLK_s:
      A.setlocation(A.getx(), A.gety() + 5);
      break;
    case SDLK_d:
      A.setlocation(A.getx() + 5, A.gety());
      break;
    case SDLK_a:
      A.setlocation(A.getx() - 5, A.gety());
      break;
    case SDLK_w:
      A.setlocation(A.getx(), A.gety() - 5);
      break;
    case SDLK_p:
      A.shoot();
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
  //player_tex = texture::sprite("./Sprites/Player.png", grenderer);
  //enemy_tex = texture::sprite("./Sprites/Enemy.png", grenderer);
  bg_temp = texture::sprite("./Sprites/bg.jpg", grenderer);
  is_running = true;
  SDL_Event e;
  Player A("./Sprites/Player.png", grenderer);
  Enemy B("./Sprites/Enemy.png", grenderer);

}

Game::~Game() {}