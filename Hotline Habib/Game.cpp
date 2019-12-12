
#include "Game.h"
#include <fstream>

GameObject *Player;
//GameObject *Enemy[5];
Background *background;
Map *map;

SDL_Rect camera = {0, 0, 1080, 720};

// Camera *camera;
SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
    Door1 = false;
    Door2 = false;
    Door3 = false;
    //Key key;
    // Paper paper;
    makemap("readmap.txt");
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
    //     Enemy[0] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 60, 2, 150);
    //     Enemy[1] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 700, 60, 2, 150);
    //     Enemy[2] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 560, 2, 150);
    //     Enemy[3] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 390, 360, 2, 150);
    //     Enemy[4] = new GameObject("./Sprites/Enemy/Enemy_updown.png", 700, 560, 2, 150);
    // //
    background = new Background("./Sprites/Map/Level_No_Doors1.png");

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

    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            Player->ChangeSprite("./Sprites/Player/player_moving_up.png");
            Player->mVelY -= GameObject::DOT_VEL;
            // Player->sety(Player->gety() + Player->mVelY);
            break;
        case SDLK_DOWN:
            Player->ChangeSprite("./Sprites/Player/player_moving_down.png");
            Player->mVelY += GameObject::DOT_VEL;
            // Player->sety(Player->gety() + Player->mVelY);
            break;
        case SDLK_LEFT:
            Player->ChangeSprite("./Sprites/Player/player_moving_left.png");
            Player->mVelX -= GameObject::DOT_VEL;
            // Player->setx(Player->getx() + Player->mVelX);
            break;
        case SDLK_RIGHT:
            Player->ChangeSprite("./Sprites/Player/player_moving_right.png");
            Player->mVelX += GameObject::DOT_VEL;
            // Player->setx(Player->getx() + Player->mVelX);
            break;
        }
    }

    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            Player->ChangeSprite("./Sprites/Player/player_moving_up.png");
            Player->mVelY += GameObject::DOT_VEL;
            break;
        case SDLK_DOWN:
            Player->ChangeSprite("./Sprites/Player/player_moving_down.png");
            Player->mVelY -= GameObject::DOT_VEL;
            break;
        case SDLK_LEFT:
            Player->ChangeSprite("./Sprites/Player/player_moving_left.png");
            Player->mVelX += GameObject::DOT_VEL;
            break;
        case SDLK_RIGHT:
            Player->ChangeSprite("./Sprites/Player/player_moving_right.png");
            Player->mVelX -= GameObject::DOT_VEL;
            break;
        }
    }
    Player->sety(Player->gety() + Player->mVelY);
    Player->setx(Player->getx() + Player->mVelX);

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

    Player->Update();
    background->BG_Update();
    // for (int i = 0; i < 5; i++)
    // {
    //     Enemy[i]->Path(0, 0, 100, 0, 100, 100, 0, 100);
    //     Enemy[i]->Update();

    //     if (Enemy[i]->returnclose())
    //     {
    //         Enemy[i]->ApproachPlayer(Player);
    //         Enemy[i]->Update();
    //     }
    //     else
    //     {
    //         if (Enemy[i]->IsPlayerClose(Player))
    //         {
    //             Enemy[i]->ApproachPlayer(Player);
    //             Enemy[i]->Update();
    //         }
    //         else
    //         {
    //             Enemy[i]->Path(array[i][0], array[i][1], array[i][2], array[i][3], array[i][4], array[i][5], array[i][6], array[i][7]);
    //             Enemy[i]->Update();
    //         }
    //     }

    //     Enemy[i]->Update();

    //     if (Collision(Player->GetDRect(), Enemy[i]->GetDRect()))
    //     {
    //         if (Game::collides <= 50)
    //         {
    //             Game::collides++;
    //         }

    //         if (Game::collides > 50)
    //         {
    //             Game::isRunning = false;
    //         }
    //     }

    // camera.x = (Player->getx() + 50) - 560;
    // camera.y = (Player->getx() + 50) - 360;

    //Keep the camera in bounds
    // if (camera.x < 0)
    // {
    //     camera.x = 0;
    // }
    // if (camera.y < 0)
    // {
    //     camera.y = 0;
    // }
    // if (camera.x > 1800 - camera.w)
    // {
    //     camera.x = 1800 - camera.w;
    // }
    // if (camera.y > 1300 - camera.h)
    // {
    //     camera.y = 1300 - camera.h;
    // }
    //    }

    // background->BG_Cam(Player->getx(), Player->gety());
}

void Game::render()
{
    SDL_RenderClear(renderer);
    background->BG_Render();
    Player->Render();
    //Enemy[0]->Render();
    //Enemy[1]->Render();
    // Enemy[2]->Render();
    // Enemy[3]->Render();
    // Enemy[4]->Render();

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
    //for (int i = 0; i < 5; i++)
    // {
    //   Enemy[i] = nullptr;
    // delete Enemy[i];
    //}
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
    for (int i = 0; i <= 16; i += 4)
    {
        if (x >= collision[i] and x <= collision[i + 1] and y >= collision[i + 2] and y <= collision[i + 3])
        {
            return true;
        }
    }
    return false;
    // }
    // if (x >= 180 & x <= 900 & y >= 20 & y <= 25)
    // {
    //     return true;
    // }
    // if (x >= 200 & x <= 205 & y >= 35 & y <= 315)
    // {
    //     return true;
    // }
    // if (x >= 340 and x <= 345 and y >= 25 and y <= 125)
    // {
    //     return true;
    // }
    // if (x >= 340 and x <= 345 and y >= 180 and y <= 315)
    // {
    //     return true;
    // }
    // if (x >= 340 and x <= 345 and y >= 25 and y <= 125)
    // {
    //     return true;
    // }
    // if (x >= 600 and x <= 875 and y >= 340 and y <= 345)
    // {
    //     return true;
    // }
    // if (x >= 870 and x <= 875 and y >= 70 and y <= 345)
    // {
    //     return true;
    // }
    // if (x >= 305 and x <= 555 and y >= 325 and y <= 330)
    // {
    //     return true;
    // }
    // if (x >= 165 and x <= 250 and y >= 325 and y <= 330)
    // {
    //     return true;
    // }
    // if (x >= 155 and x <= 160 and y >= 330 and y <= 545)
    // {
    //     return true;
    // }
    // if (x >= 180 and x <= 425 and y >= 535 and y <= 540)
    // {
    //     return true;
    // }
    // if (x >= 425 and x <= 435 and y >= 330 and y <= 610)
    // {
    //     return true;
    // }
    // if (x >= 755 and x <= 760 and y >= 365 and y <= 615)
    // {
    //     return true;
    // }
    // if (x >= 410 and x <= 760 and y >= 620 and y <= 625)
    // {
    //     return true;
    // }
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

    if (x > 280 & x<290 & y> 330 & y < 340) // & key.getstate() == true)
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
void Game::makemap(std::string filename)
{
    std::string line;
    std::ifstream myfile(filename);
    if (myfile.is_open())
    {
        int i = 0;
        while (getline(myfile, line))
        {
            collision[i] = stoi(line);
            i++;
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";
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