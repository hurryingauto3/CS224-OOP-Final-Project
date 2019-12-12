
#include "Game.h"

GameObject *Player;
GameObject *Enemy[5];
Background *background;
uicomp *UI;

Map *map;

// SDL_Rect camera = {0, 0, 1080, 720};

int array[10][8] = {{390, 60, 420, 60, 420, 310, 390, 310},
                    {240, 50, 320, 50, 320, 300, 240, 300},
                    {470, 330, 730, 330, 730, 610, 470, 610}};

// Camera *camera;
SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
    Door1 = false;
    Door2 = false;
    Door3 = false;
    KeyFound = false;
    PaperFound = false;
    collides = 0;
    isGameRunning = true;
}

Game::~Game() {}

void Game::init(const std::string title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized..." << std::endl;
        const char *name = title.c_str();
        window = SDL_CreateWindow(name, xpos, ypos, width, height, flags);
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

    Player = new GameObject("./Sprites/Player/player_stat.png", 970, 70, 2, 150);
    // camera = new Camera("./Sprite/Level_No_Doors");
    Enemy[0] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 60, 2, 150);
    Enemy[1] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 700, 60, 2, 150);
    Enemy[2] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 560, 2, 150);
    Enemy[3] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 360, 2, 150);
    Enemy[4] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 700, 560, 2, 150);

    background = new Background("./Sprites/Map/Level_No_Doors1.png");

    UI = new uicomp("./SplashScreens/MainMenu.png");

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
            if (!TerrainCollide(Player->getx(), Player->gety()))
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_up.png");
                Player->Setloc(Player->getx(), Player->gety() - 5);
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_up.png");
                Player->Setloc(Player->getx(), Player->gety() + 20);
            }
        case SDLK_s:
            if (!TerrainCollide(Player->getx(), Player->gety()))
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_down.png");
                Player->Setloc(Player->getx(), Player->gety() + 5);
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_down.png");
                Player->Setloc(Player->getx(), Player->gety() - 20);
            }

        case SDLK_a:
            if (!TerrainCollide(Player->getx(), Player->gety()))
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_left.png");
                Player->Setloc(Player->getx() - 5, Player->gety());
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_left.png");
                Player->Setloc(Player->getx() + 20, Player->gety());
            }

        case SDLK_d:
            if (!TerrainCollide(Player->getx(), Player->gety()))
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_right.png");
                Player->Setloc(Player->getx() + 5, Player->gety());
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/Player/player_moving_right.png");
                Player->Setloc(Player->getx() - 20, Player->gety());
            }
        case SDLK_RETURN:
            if (!(UI->getstart()))
            {
                if (UI->getUp())
                {
                    UI->setstart(true);
                }
                else
                    Game::isRunning = false;
            }
        case SDLK_UP:
        {
            if (!(UI->getstart()))
            {
                UI->SetSprite("./SplashSceens/MainMenu2.png");
                UI->setUP(true);
                std::cout << "UP true" << std::endl;
            }
        }
        case SDLK_DOWN:
        {
            if (!(UI->getstart()))
            {
                UI->SetSprite("./SplashSceens/MainMenu3.png");
                UI->setUP(false);
                std::cout << "UP down" << std::endl;
            }
        }
        case SDLK_p:
            Player->ChangeSprite("./Sprites/Player/player_shoot.png");
        }
        // case SDLK_o:
        //     DoorOpen(Player->getx(), Player->gety());
        //     std::cout << "O Pressed" << std::endl;
        // }
    }
    if (e.type == SDL_KEYUP)
    {
        Player->ChangeSprite("./Sprites/Player/player_stat.png");
    }
}

void Game::update()
{
    if (!(UI->getstart()))
    {
        UI->UI_Update();
    }
    else
    {
        Player->Update();
        background->BG_Update();
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
                    Enemy[i]->Path(array[i][0], array[i][1],
                                   array[i][2], array[i][3], array[i][4],
                                   array[i][5], array[i][6], array[i][7]);
                    Enemy[i]->Update();
                }
            }

            Enemy[i]->Update();

            if (Collision(Player->GetDRect(), Enemy[i]->GetDRect()))
            {
                if (Game::collides <= 1)
                {
                    Game::collides++;
                }

                if (Game::collides > 1)
                {
                    Game::isGameRunning = false;
                }
            }
        }
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    if (!(UI->getstart()))
    {
        UI->UI_Render();
    }
    else
    {
        background->BG_Render();

        Player->Render();

        Enemy[0]->Render();
        Enemy[1]->Render();
        Enemy[2]->Render();
        Enemy[3]->Render();
        Enemy[4]->Render();
    }
    // UI->UI_Render();
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
    Player = nullptr;
    for (int i = 0; i < 5; i++)
    {
        Enemy[i] = nullptr;
        delete Enemy[i];
    }
    background = nullptr;
    map = nullptr;

    delete background;
    delete map;
    delete Player;
}

bool Game::running()
{
    return isRunning;
}

bool Game::Collision(SDL_Rect a, SDL_Rect b)
{
    if (a.y >= b.y + b.h)
        return false;
    if (a.x >= b.x + b.w)
        return false;
    if (a.y + a.h <= b.y)
        return false;
    if (a.x + a.w <= b.x)
        return false;
    if (a.y == b.y && a.h == b.h && a.x == b.x && a.w == b.w)
        return false;
    else
        return true;
}

bool Game::TerrainCollide(int x, int y)
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
        if (Game::Door1 & x >= 580 & x <= 590)
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

// void Game::MovementAlgo(GameObject *A, GameObject *Player, int array[8])
// {
//     A->Path(0, 0, 100, 0, 100, 100, 0, 100);
//     A->Update();

//     if (A->returnclose())
//     {
//         A->ApproachPlayer(Player);
//         A->Update();
//     }
//     else
//     {
//         if (A->IsPlayerClose(Player))
//         {
//             A->ApproachPlayer(Player);
//             A->Update();
//         }
//         else
//         {
//             A->Path(array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7]);
//             A->Update();
//         }
//     }
// }

void Game::run()
{

    while (Game::running())
    {
        Game::handleEvents();
        Game::update();
        Game::render();
    }
}