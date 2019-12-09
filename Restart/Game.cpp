#include "Game.h"

GameObject *Player;
GameObject *Enemy;
Background *background;
Map *map;
Bullet *bullet;
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
    //Initialize SDL Video and Audio
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    //Initialize SDL Mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

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
    Enemy = new GameObject("./Sprites/player_stat.png", 0, 0);
    background = new Background("./Sprites/Level_No_Doors1.png");
    map = new Map();
}

void Game::handleEvents()
{
    //Start playing bg music
    Mix_PlayMusic(backgroundSound, -1);
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
            Mix_PlayChannel(-1, foot1, 0);
            if (!TerrainCollide(Player->getx(), Player->gety(), Door1, Door2, Door3))
            {
                Player->ChangeSprite("./Sprites/player_moving_up.png");
                Player->Setloc(Player->getx(), Player->gety() - 10);
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/player_moving_up.png");
                Player->Setloc(Player->getx(), Player->gety() + 5);
            }
        case SDLK_s:
            Mix_PlayChannel(-1, foot2, 0);
            if (!TerrainCollide(Player->getx(), Player->gety(), Door1, Door2, Door3))
            {
                Player->ChangeSprite("./Sprites/player_moving_down.png");
                Player->Setloc(Player->getx(), Player->gety() + 10);
                std::cout << Player->getx() << ", " << Player->gety() << std::endl;
                break;
            }
            else
            {
                Player->ChangeSprite("./Sprites/player_moving_down.png");
                Player->Setloc(Player->getx(), Player->gety() - 5);
            }

        case SDLK_a:
            Mix_PlayChannel(-1, foot1, 0);
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
                Player->Setloc(Player->getx() + 5, Player->gety());
            }

        case SDLK_d:
            Mix_PlayChannel(-1, foot2, 0);
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
                Player->Setloc(Player->getx() + -10, Player->gety());
            }
        case SDLK_p:
            Player->ChangeSprite("./Sprites/player_shoot.png");
            Mix_PlayChannel(-1, shot, 0);
        case SDLK_o:
            Mix_PlayChannel(-1, dooropen, 0);
            DoorOpen(Player->getx(), Player->gety());
            std::cout << "O Pressed" << std::endl;

        case SDLK_0:
            Mix_HaltMusic();
            Mix_PlayMusic(backgroundSound, -1);

        case SDLK_1:
            Mix_HaltMusic();
            Mix_PlayMusic(track1, -1);

        case SDLK_2:
            Mix_HaltMusic();
            Mix_PlayMusic(track2, -1);

        case SDLK_3:
            Mix_HaltMusic();
            Mix_PlayMusic(track3, -1);

        case SDLK_4:
            Mix_HaltMusic();
            Mix_PlayMusic(track4, -1);

        case SDLK_5:
            Mix_HaltMusic();
            Mix_PlayMusic(track5, -1);

        case SDLK_6:
            Mix_HaltMusic();
            Mix_PlayMusic(track6, -1);

        case SDLK_7:
            Mix_HaltMusic();
            Mix_PlayMusic(track7, -1);
        }
    }
}
void Game::update()
{
    Player->Update();
    // camera->Cam_Update(Player->getx(), Player->gety());
    background->BG_Update();
    Enemy->Path(1, 0, 1, 0, 1, 0, 1, 0);
    Enemy->Update();
}

void Game::render()
{
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    std::cout << "Window Destroyed" << std::endl;
    Mix_FreeMusic(backgroundSound);
    Mix_FreeMusic(track1);
    Mix_FreeMusic(track2);
    Mix_FreeMusic(track3);
    Mix_FreeMusic(track4);
    Mix_FreeMusic(track5); //Destroy all music
    Mix_FreeMusic(track6);
    Mix_FreeMusic(track7);
    Mix_FreeChunk(Click);
    Mix_FreeChunk(foot2);
    Mix_FreeChunk(foot1);
    Mix_FreeChunk(shot);
    Mix_CloseAudio();
    std::cout << "Music Disabled" << std::endl;
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
}

void Game::renderer()

{
    SDL_RenderClear(renderer);
    background->BG_Render();
    Player->Render();
    Enemy->Render();
    SDL_RenderPresent(renderer);
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
== == == =
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
