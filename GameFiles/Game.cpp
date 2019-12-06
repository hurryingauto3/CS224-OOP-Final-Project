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
    camera.x = A->getx() - 540;
    camera.y = A->gety() - 360;

    B->ApproachPlayer(A);

    B->IsPlayerClose(A);
    if (B->getplayercloseby())
    {
      B->ApproachPlayer(A);
    }
    else
    {
      B->Path(0, 0, 100, 0, 100, 100, 0, 100);
    }
    B->obj_update();

    C->obj_update();
    if (camera.x < 0)
    {
      camera.x = 0;
    }
    if (camera.y < 0)
    {
      camera.y = 0;
    }
    if (camera.x > camera.w)
    {
      camera.x = camera.w;
    }
    if (camera.y > camera.h)
    {
      camera.y = camera.h;
    }
  }
  ui->obj_update();
}

void Game::render()
{
  SDL_RenderClear(grenderer);
  if (!onSplashScreen)
  {
    C->obj_render();
    A->obj_render();
    B->obj_render(A);
  }
  else
    ui->obj_render();
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
      A->setlocation(A->getx(), A->gety() + A->getSpeed);
      break;
    case SDLK_d:
      A->setlocation(A->getx() + A->getSpeed, A->gety());
      break;
    case SDLK_F4: //pressing this should kill the process
      if (onSplashScreen)
        ui->setEndGame(true); //SDL_DestroyWindow(window);
      break;
    case SDLK_RETURN:
      if (onSplashScreen)
        onSplashScreen = false;
      break;
    case SDLK_a:
      A->setlocation(A->getx() - A->getSpeed, A->gety());
      break;
    case SDLK_w:
      A->setlocation(A->getx(), A->gety() - A->getSpeed);
      break;
    case SDLK_p:
      A->shoot();
      break;
    case SDL_MOUSEMOTION:
      A->obj_update();
    case SDL_MOUSEBUTTONDOWN:
      mousePress(Event.button);
    default:
      break;
    }
    //Get mouse position
    //SDL Function for gettting mousestate, current location.
  case (SDL_MOUSEMOTION):
  {
    SDL_GetMouseState(&x, &y);
    std::cout << x << " " << y << std::endl;
  }
  // case (SDL_MOUSEBUTTONDOWN): //checks if mousebutton pressed
  // {
  //   SDL_GetMouseState(&x, &y);
  //   mousePress(Event.button);
  // }
  default:
    break;
  }
};
void Game::mousePress(SDL_MouseButtonEvent &b)
{
  if (b.button == SDL_BUTTON_LEFT)
  {
    bullet = new Bullet("./Sprites/MainMenu.png", grenderer);
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
  camera = {0, 0, 1080, 720};
  is_running = true;
  onSplashScreen = true;
  SDL_Event e;
  A = new Player("./Sprites/Player.png", grenderer);
  B = new Enemy("./Sprites/Enemy.png", grenderer); //made both classes into popinters so i could render more effeciently
  C = new BG("./Sprites/level_BG.png", grenderer);
  ui = new ui_simplified("./Sprites/MainMenu.png", grenderer);
}

Game::~Game() {}
