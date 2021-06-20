#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, const char** argv) {

    if( SDL_Init(SDL_INIT_VIDEO) > 0 )
    {
        std::cout << "SDL_Init failed. SDL_ERROR: " << SDL_GetError() << std::endl;

        return 1;
    }

    std::cout << "SDL_Init it worked!" << std::endl;

    if(! (IMG_Init(IMG_INIT_PNG)) )
    {
        std::cout << "IMG_Init failed. SDL_ERROR: " << SDL_GetError() << std::endl;

        return 1;
    }

    std::cout << "IMG_Init it worked!" << std:: endl;

    RenderWindow window("GAME v1.0", 1280, 720);

    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while ( SDL_PollEvent(&event) )
        {
            if ( event.type == SDL_QUIT )
            {
                gameRunning = false;
                
                std::cout << "Quit..." << std::endl;
            }
        }
        
    }
    

    window.cleanUp();
    SDL_Quit();



    return 0;
}