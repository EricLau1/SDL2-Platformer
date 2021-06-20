#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height):
    window(NULL), renderer(NULL)
{

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if ( window == NULL )
    {
        std::cout << "SDL_CreateWindow failed. SDL_ERROR: " << SDL_GetError() << std::endl;

        return;
    }

    std::cout << "SDL_CreateWindow it worked!" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if ( renderer == NULL )
    {
        std::cout << "SDL_CreateRenderer failed. SDL_ERROR: " << SDL_GetError() << std::endl;

        return;  
    }

     std::cout << "SDL_CreateRenderer it worked!" << std::endl;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}