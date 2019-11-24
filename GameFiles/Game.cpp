#include "Game.hpp"

SDL_Texture *player_tex;
SDL_Texture *enemy_tex;
SDL_Texture *bg_temp;
SDL_Rect s_rect, d_rect1, d_rect2, d_rect3;

bool Game::runcheck()
{
  return is_running;
}
void Game::update()
{

  d_rect1.h = 128;
  d_rect1.w = 128;
  d_rect1.x = A.getx();
  d_rect1.y = A.gety();
  d_rect2.h = 128;
  d_rect2.w = 128;
  d_rect2.x = B.getx();
  d_rect2.y = B.gety();
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
  SDL_RenderCopy(grenderer, player_tex, NULL, &d_rect1);
  SDL_RenderCopy(grenderer, enemy_tex, NULL, &d_rect2);
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
  SDL_Surface *tempSurf1;
  SDL_Surface *tempSurf2;
  SDL_Surface *bg;
  tempSurf1 = IMG_Load("./Sprites/Player.png");
  tempSurf2 = IMG_Load("./Sprites/Enemy.png");
  bg = IMG_Load("./Sprites/bg.jpg");
  player_tex = SDL_CreateTextureFromSurface(grenderer, tempSurf1);
  enemy_tex = SDL_CreateTextureFromSurface(grenderer, tempSurf2);
  bg_temp = SDL_CreateTextureFromSurface(grenderer, bg);
  SDL_FreeSurface(tempSurf1);
  SDL_FreeSurface(tempSurf2);
  SDL_FreeSurface(bg);
  is_running = true;
  SDL_Event e;
  Player A;
  Enemy B;
}

Game::~Game() {}