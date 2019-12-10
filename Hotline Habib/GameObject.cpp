#include "GameObject.h"
#include "Texture.h"

GameObject::GameObject(std::string Sprite, int xpos, int ypos)
{
    this->Sprite = Sprite;
    this->xpos = xpos;
    this->ypos = ypos;
    Obj_Tex = TextureManager::LoadTexture(this->Sprite);
    IsPlayerClosebool = false;
    mVelX = 0;
    mVelY = 0;
}

GameObject::GameObject(std::string Sprite, int xpos, int ypos, int frames, int speed) : GameObject(Sprite, xpos, ypos)
{
    this->frames = frames;
    this->speed = speed;
    this->animated = true;
    IsPlayerClosebool = false;
    mVelX = 0;
    mVelY = 0;
}
void GameObject::Render() { SDL_RenderCopy(Game::renderer, Obj_Tex, &sRect, &dRect); }

void GameObject::Update()
{

    if (animated)
    {
        sRect.x = sRect.w * static_cast<int>((SDL_GetTicks() / speed % frames));
        sRect.y = 0;
        sRect.w = 16;
        sRect.h = 24;
    }
    else
    {
        sRect.h = 24;
        sRect.w = 32;
        sRect.x = 0;
        sRect.y = 0;
    }
    dRect.x = xpos;
    dRect.y = ypos;
    dRect.w = sRect.w * 2.5;
    dRect.h = sRect.h * 2.5;
}
int GameObject::getx() { return xpos; }

int GameObject::gety() { return ypos; }

void GameObject::Setloc(int x, int y)
{
    this->xpos = x;
    this->ypos = y;
}

void GameObject::ChangeSprite(std::string Sprite)
{
    this->Sprite = Sprite;
    this->Obj_Tex = TextureManager::LoadTexture(this->Sprite);
}
