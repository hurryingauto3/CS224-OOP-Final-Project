#include "Game.hpp"

bool Game::runcheck()
{
  return is_running;
}
void Game::update()
{
  if (!onSplashScreen)
  {
    A->obj_update();
    B->angle(A);
    B->obj_update();
    bullet->obj_update();
    bullet->setlocation(A->getx(), A->gety());

    // B->ApproachPlayer(A);

    // B->IsPlayerClose(A);
    // if (B->getplayercloseby())
    // {
    //   B->ApproachPlayer(A);
    // }
    // else
    // {
    //   B->Path(0, 0, 100, 0, 100, 100, 0, 100);
    // }
    B->obj_update();

    C->obj_update(-A->getx(), -A->gety());
  }
  else
    ui->obj_update();
}
void Game::render()
{
  SDL_RenderClear(grenderer);
  if (!onSplashScreen)
  {
    C->obj_render((A->getx()), (A->gety()), &temp);
    A->obj_render();
    B->obj_render(A);
    bullet->obj_render(A);
  }
  else
    ui->obj_render();
  SDL_RenderPresent(grenderer);
}
void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(grenderer);
  Mix_FreeMusic(backgroundSound);
  Mix_FreeChunk(Click);
  Mix_FreeChunk(foot2);
  Mix_FreeChunk(foot1);
  Mix_FreeChunk(shot);
  Mix_CloseAudio();
  SDL_Quit();
}
void Game::handle_event()
{
  SDL_Event Event;
  bool mouseClicked;
  mouseClicked = false;
  int x, y; //Mouse coordinates current
  SDL_PollEvent(&Event);
  switch (Event.type)
  {
  case SDL_QUIT:
    is_running = false;

  case SDL_KEYDOWN: //both classes are pointers now so used arrows
    switch (Event.key.keysym.sym)
    {
    case SDLK_s:
      Mix_PlayChannel(-1, foot2,0);
      A->setlocation(A->getx(), A->gety() + A->getSpeed());
      break;
    case SDLK_d:
      Mix_PlayChannel(-1, foot2,0);
      A->setlocation(A->getx() + A->getSpeed(), A->gety());
      //camera.x += A->getSpeed;
      //C->getx() + A->getSpeed();
      break;
    case SDLK_F4: //pressing this should kill the process
      if (onSplashScreen)
        ui->setEndGame(true); //SDL_DestroyWindow(window);
      break;
    case SDLK_RETURN:
      if (onSplashScreen)
        Mix_PlayChannel(-1, Click,0);
        Mix_HaltMusic();
        onSplashScreen = false;
      break;
    case SDLK_a:

      if (!collision(A->getdrekt(), B->getdrekt()))
      {
        A->setlocation(A->getx() - A->getSpeed(), A->gety());
      }
      Mix_PlayChannel(-1, foot1,0);
      break;
    case SDLK_w:
      if (!collision(A->getdrekt(), B->getdrekt()))
      {
        A->setlocation(A->getx(), A->gety() - A->getSpeed());
      }

      A->setlocation(A->getx() - A->getSpeed(), A->gety());
      A->obj_update();
      Mix_PlayChannel(-1, foot1,0);

        
    }
  case (SDLK_SPACE):
  {
    SDL_GetMouseState(&x, &y);
    bullet = new Bullet(*A, x, y, "./Sprites/temp_bullet.png", grenderer);
    std::cout << x << " " << y << std::endl;
  }

  default:
    break;
  }
};

Game::Game()
{
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, 0);
  grenderer = SDL_CreateRenderer(window, -1, 0);
  if (grenderer)
  {
    SDL_SetRenderDrawColor(grenderer, 206, 140, 140, 255);
  }
  is_running = true;
  onSplashScreen = true;
  SDL_Event e;
  //SDL_Rect camera;
  A = new Player("./Sprites/Player.png", grenderer);
  B = new Enemy("./Sprites/Enemy.png", grenderer); //made both classes into popinters so i could render more effeciently
  C = new BG("./Sprites/level_BG.png", grenderer);
  temp = {C->BG::getsrect()};
  ui = new ui_simplified("./Sprites/MainMenu.png", grenderer);
  bullet = new Bullet();
}

Game::~Game() {}
