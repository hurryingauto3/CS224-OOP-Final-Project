#include "Game.hpp"

SDL_Texture *player_tex;
SDL_Texture *enemy_tex;
SDL_Rect s_rect, d_rect1, d_rect2;


bool Game::is_runningzz()
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
  d_rect2.x = 50;
  d_rect2.y = 50;
}

void Game::render()
{
  SDL_RenderClear(grenderer);
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
void Game::HandleEvent()
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
  window = SDL_CreateWindow("Tester", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, 0);
  grenderer = SDL_CreateRenderer(window, -1, 0);
  if (grenderer)
  {
    SDL_SetRenderDrawColor(grenderer, 206, 140, 140, 255);
  }

  is_running = true;


  SDL_Surface *tempSurf1;
  SDL_Surface *tempSurf2;
  tempSurf1 = IMG_Load("D:/CS224-OOP-Final-Project/Sprites/Player.png");
  tempSurf2 = IMG_Load("D:/CS224-OOP-Final-Project/Sprites/Enemy.png");
  player_tex = SDL_CreateTextureFromSurface(grenderer, tempSurf1);
  enemy_tex = SDL_CreateTextureFromSurface(grenderer, tempSurf2);
  SDL_FreeSurface(tempSurf1);
  SDL_FreeSurface(tempSurf2);
  is_running = true;
  SDL_Event e;
  Player A;
  Enemy B(20, 20);
}

Game::~Game() {}