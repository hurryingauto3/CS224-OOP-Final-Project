#include <SDL.h>
#include <SDL_image.h>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 20;

//The dot dimensions
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

//The dot
class Dot
{
private:
    //The X and Y offsets of the dot
    int x, y;

    //The velocity of the dot
    int xVel, yVel;

public:
    //Initializes the variables
    Dot();

    //Takes key presses and adjusts the dot's velocity
    void handle_input();

    //Moves the dot
    void move();

    //Shows the dot on the screen
    void show();

    //Sets the camera over the dot
    void set_camera();
};
//The surfaces
SDL_Surface *dot = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The camera
SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

void Dot::move()
{
    //Move the dot left or right
    x += xVel;

    //If the dot went too far to the left or right
    if ((x < 0) || (x + DOT_WIDTH > LEVEL_WIDTH))
    {
        //move back
        x -= xVel;
    }

    //Move the dot up or down
    y += yVel;

    //If the dot went too far up or down
    if ((y < 0) || (y + DOT_HEIGHT > LEVEL_HEIGHT))
    {
        //move back
        y -= yVel;
    }
}

void Dot::set_camera()
{
    //Center the camera over the dot
    camera.x = (x + DOT_WIDTH / 2) - SCREEN_WIDTH / 2;
    camera.y = (y + DOT_HEIGHT / 2) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds.
    if (camera.x < 0)
    {
        camera.x = 0;
    }
    if (camera.y < 0)
    {
        camera.y = 0;
    }
    if (camera.x > LEVEL_WIDTH - camera.w)
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if (camera.y > LEVEL_HEIGHT - camera.h)
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }
}

void Dot::show()
{
    //Show the dot
    apply_surface(x - camera.x, y - camera.y, dot, screen);
}

int main()
{
    //While the user hasn't quit
    while (quit == false)
    {
        //Start the frame timer
        fps.start();

        //While there's events to handle
        while (SDL_PollEvent(&event))
        {
            //Handle events for the dot
            myDot.handle_input();

            //If the user has Xed out the window
            if (event.type == SDL_QUIT)
            {
                //Quit the program
                quit = true;
            }
        }

        //Move the dot
        myDot.move();

        //Set the camera
        myDot.set_camera();

        //Show the background
        apply_surface(0, 0, background, screen, &camera);

        //Show the dot on the screen
        myDot.show();

        //Update the screen
        if (SDL_Flip(screen) == -1)
        {
            return 1;
        }

        //Cap the frame rate
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
        {
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
        }
    }
}