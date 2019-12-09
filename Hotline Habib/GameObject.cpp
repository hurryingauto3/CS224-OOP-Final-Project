#include "GameObject.h"
#include "Texture.h"

GameObject::GameObject(char *Sprite, int xpos, int ypos)
{
    this->Sprite = Sprite;
    this->xpos = xpos;
    this->ypos = ypos;
    Obj_Tex = TextureManager::LoadTexture(this->Sprite);
    // SDL_QueryTexture(this->Obj_Tex, NULL, NULL, &this->texturewidth, &this->textureheight);
    // this->framewidth = this->texturewidth / 2;
    // this->frameheight = this->textureheight;
}

GameObject::GameObject(char *Sprite, int xpos, int ypos, int frames, int speed) : GameObject(Sprite, xpos, ypos)
{
    this->frames = frames;
    this->speed = speed;
    this->animated = true;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, Obj_Tex, &sRect, &dRect);
}

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
    dRect.w = sRect.w * 2;
    dRect.h = sRect.h * 2;
}
int GameObject::getx()
{
    return xpos;
}

int GameObject::gety()
{
    return ypos;
}
void GameObject::Setloc(int x, int y)
{
    this->xpos = x;
    this->ypos = y;
}

// SDL_Texture *GameObject::GetTex()
// {
//     return this->Obj_Tex;
// }
void GameObject::ChangeSprite(char *Sprite)
{
    this->Sprite = Sprite;
    this->Obj_Tex = TextureManager::LoadTexture(this->Sprite);
}

void GameObject::Path(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if (this->ypos == y1 && this->xpos != x2)
    {
        this->Setloc(this->xpos + 1, this->ypos);
        this->Update();
    }
    else if (this->xpos == x2 && this->ypos != y3)
    {
        this->Setloc(this->xpos, this->ypos + 1);
        this->Update();
    }
    else if (this->ypos == y3 && this->xpos != x1)
    {
        this->Setloc(this->xpos - 1, this->ypos);
        this->Update();
    }
    else if (this->xpos == x1 && this->ypos != y1)
    {
        this->Setloc(this->xpos, this->ypos - 1);
        this->Update();
    }
}

// int *GameObject::GetTexW() { return &this->texturewidth; }
// int *GameObject::GetTexH() { return &this->textureheight; }
// int *GameObject::GetFrameW() { return &this->framewidth; }
// int *GameObject::GetFrameH() { return &this->framewidth; }