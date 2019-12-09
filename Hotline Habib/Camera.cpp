// #include "Camera.h"

// Camera::Camera(char *Sprite)
// {
//     CamTex = TextureManager::LoadTexture(Sprite);
// }
// void Camera::Cam_Update(int x, int y)
// {
//     dRect.h = 1080;
//     dRect.w = 720;
//     dRect.x = x - 560;
//     dRect.y = y - 360;

//     if (dRect.x < 0)
//         dRect.x = 0;
//     if (dRect.y < 0)
//         dRect.y = 0;
// }
// void Camera::Cam_Render()
// {
//     SDL_RenderCopy(Game::renderer, CamTex, nullptr, &dRect); //sRect is null for now
// }