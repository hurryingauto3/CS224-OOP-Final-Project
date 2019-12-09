
#include "Game.h"

GameObject *Player;
GameObject *Enemy[3];
Background *background;
Map *map;
// Camera *camera;

SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
    Door1 = false;
    Door2 = false;
    Door3 = false;
    KeyFound = false;
    PaperFound = false;
}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window Created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created" << std::endl;
        }

        isRunning = true;
    }

    Player = new GameObject("./Sprites/player_stat.png", 970, 70, 2, 150);
    // camera = new Camera("./Sprite/Level_No_Doors");
    Enemy[0] = new GameObject("./Sprites/player_stat.png", 390, 60, 2, 150);
    Enemy[1] = new GameObject("./Sprites/player_stat.png", 240, 50, 2, 150);
    Enemy[2] = new GameObject("./Sprites/player_stat.png", 470, 330, 2, 150);
    background = new Background("./Sprites/Level_No_Doors1.png");
    map = new Map();
}

void Game::handleEvents()
{
    SDL_Event e;
    SDL_PollEvent(&e);

    if (e.type == SDL_QUIT)
    {
        isRunning = false;
    }

    // If a key was released else
    if (e.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_w:
            if (!TerrainCollide(Player->getx(), Player->gety(), Door1, Door2, Door3))
            {
                Player->ChangeSprite("./Sprites/player_moving_up.png");
                Player->Setloc(Player->getx(), Player->gety() - 5);
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/player_moving_up.png");
                Player->Setloc(Player->getx(), Player->gety() + 20);
            }
        case SDLK_s:
            if (!TerrainCollide(Player->getx(), Player->gety(), Door1, Door2, Door3))
            {
                Player->ChangeSprite("./Sprites/player_moving_down.png");
                Player->Setloc(Player->getx(), Player->gety() + 5);
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/player_moving_down.png");
                Player->Setloc(Player->getx(), Player->gety() - 20);
            }

        case SDLK_a:
            if (!TerrainCollide(Player->getx(), Player->gety(), Door1, Door2, Door3))
            {
                Player->ChangeSprite("./Sprites/player_moving_left.png");
                Player->Setloc(Player->getx() - 5, Player->gety());
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/player_moving_left.png");
                Player->Setloc(Player->getx() + 20, Player->gety());
            }

        case SDLK_d:
            if (!TerrainCollide(Player->getx(), Player->gety(), Door1, Door2, Door3))
            {
                Player->ChangeSprite("./Sprites/player_moving_right.png");
                Player->Setloc(Player->getx() + 5, Player->gety());
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/player_moving_right.png");
                Player->Setloc(Player->getx() - 20, Player->gety());
            }
        case SDLK_p:
            Player->ChangeSprite("./Sprites/player_shoot.png");
        }
        // case SDLK_o:
        //     DoorOpen(Player->getx(), Player->gety());
        //     std::cout << "O Pressed" << std::endl;
        // }
    }
    if (e.type == SDL_KEYUP)
    {
        Player->ChangeSprite("./Sprites/player_stat.png");
    }
}
void Game::update()
{
    Player->Update();
    background->BG_Update();
    // background->BG_Cam(Player->getx(), Player->gety());
    int array[40];
    array[0] = 390;
    array[1] = 60;
    array[2] = 420;
    array[3] = 60;
    array[4] = 420;
    array[5] = 310;
    array[6] = 390;
    array[7] = 310;
    array[8] = 240;
    array[9] = 50;
    array[10] = 320;
    array[11] = 50;
    array[12] = 320;
    array[13] = 300;
    array[14] = 240;
    array[15] = 300;
    array[16] = 470;
    array[17] = 330;
    array[18] = 730;
    array[19] = 330;
    array[20] = 730;
    array[21] = 610;
    array[22] = 470;
    array[23] = 610;

    for (int i = 0; i < 3; i++)
    {
        Enemy[i]->Path(0, 0, 100, 0, 100, 100, 0, 100);
        Enemy[i]->Update();

        if (Enemy[i]->returnclose())
        {
            Enemy[i]->ApproachPlayer(Player);
            Enemy[i]->Update();
        }
        else
        {
            if (Enemy[i]->IsPlayerClose(Player))
            {
                Enemy[i]->ApproachPlayer(Player);
                Enemy[i]->Update();
            }
            else
            {
                Enemy[i]->Path(array[i], array[i + 1], array[i + 2], array[i + 3], array[i + 4], array[i + 5], array[i + 6], array[i + 7]);
                Enemy[i]->Update();
            }
        }
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    background->BG_Render();

    Player->Render();

    Enemy[0]->Render();
    Enemy[1]->Render();
    Enemy[2]->Render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    std::cout << "Window Destroyed" << std::endl;
    SDL_DestroyRenderer(renderer);
    std::cout << "Renderer Destroyed" << std::endl;
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
    return isRunning;
}

bool Game::collision(SDL_Rect a, SDL_Rect b)
{
    if (a.y >= b.y + b.h)
    {
        return false;
    }
    if (a.x >= b.x + b.w)
    {
        return false;
    }
    if (a.y + a.h <= b.y)
    {
        return false;
    }
    if (a.x + a.w <= b.x)
    {
        return false;
    }
    if (a.y == b.y && a.h == b.h && a.x == b.x && a.w == b.w)
        return false;
    else
    {
        return true;
    }
}

bool Game::TerrainCollide(int x, int y, bool door1, bool door2, bool door3)
{
    if (y <= 20 & x >= 230 & x <= 340)
    {
        return true;
    }
    if (y <= 30 & x >= 370 & x <= 870)
    {
        return true;
    }
    if (y >= 340 & x >= 370 & x <= 870)
    {
        if (door1 & x >= 580 & x <= 590)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void Game::DoorOpen(int x, int y)
{
    if (x > 580 & x < 590 & y<340 & y> 330)
    {
        Door1 = true;
        std::cout << "Door 1 Opened" << std::endl;
        background->ChangeSprite("./Sprites/Level_TV_Door.png");
    }
    else
    {
        std::cout << "Not Near Door" << std::endl;
    }

    if (x > 360 & x<370 & y> 60 & y < 80)
    {
        Door2 = true;
        std::cout << "Door 2 Opened" << std::endl;
        background->ChangeSprite("./Sprites/Level_Passage_Door.png");
    }
    else
    {
        std::cout << "Not Near Door" << std::endl;
    }

    if (x > 280 & x<290 & y> 330 & y < 340 & KeyFound == true)
    {
        Door3 = true;
        std::cout << "Door 3 Opened" << std::endl;
        background->ChangeSprite("./Sprites/Level_Teacher_Door.png");
    }
    else
    {
        std::cout << "Not Near Door" << std::endl;
    }
}