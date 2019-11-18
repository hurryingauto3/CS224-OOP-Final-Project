#include "Game.hpp"

SDL_Texture *player_tex;
SDL_Rect s_rect, d_rect;

bool Game::is_runningzz()
{
  return is_running;
}
void Game::update()
{
  d_rect.h = 64;
  d_rect.w = 64;
  d_rect.x = A.getx();
  d_rect.y = A.gety();
}
void Game::render()
{
  SDL_RenderClear(grenderer);
  SDL_RenderCopy(grenderer, player_tex, NULL, &d_rect);
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
      A.setlocation(A.getx(), A.gety() + 1);
      break;
    case SDLK_d:
      A.setlocation(A.getx() + 1, A.gety());
      break;
    case SDLK_a:
      A.setlocation(A.getx() - 1, A.gety());
      break;
    case SDLK_w:
      A.setlocation(A.getx(), A.gety() - 1);
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
  is_running = true;
  SDL_Event e;
  Player A;

  while (is_running)
  {
    while (SDL_PollEvent(&e) != 0)
    {
      if (e.type == SDL_QUIT)
      {
        is_running = false;
      }
      if (e.type == SDL_KEYDOWN)
      {
        if (e.key.keysym.sym == SDLK_w)
        {
          A.setlocation(A.getx(), A.gety() + 1);
        }

        if (e.key.keysym.sym == SDLK_s)
        {
          A.setlocation(A.getx(), A.gety() - 1);
        }
        if (e.key.keysym.sym == SDLK_d)
        {
          A.setlocation(A.getx() + 1, A.gety());
        }
        if (e.key.keysym.sym == SDLK_a)
        {
          A.setlocation(A.getx() - 1, A.gety());
        }
        std::cout << "X COORD" << A.getx() << std::endl;
        std::cout << "Y COORD" << A.gety() << std::endl;
      }
    }
  }
}

void Game::init()
{
  window = SDL_CreateWindow("Tester", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, 0);
  grenderer = SDL_CreateRenderer(window, -1, 0);
  if (grenderer)
  {
    SDL_SetRenderDrawColor(grenderer, 255, 255, 255, 255);
  }

  is_running = true;

  SDL_Surface *tempSurf = IMG_Load("D:/CS224-OOP-Final-Project/Sprites/Tester.png");
  player_tex = SDL_CreateTextureFromSurface(grenderer, tempSurf);
  SDL_FreeSurface(tempSurf);
}

Game::~Game() {}