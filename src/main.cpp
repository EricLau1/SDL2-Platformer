#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include "Utils.hpp"

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

    RenderWindow window("SDL GAME v1.0", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    std::vector<Entity> entities;

    entities.push_back(Entity(Vector2f(0, 0), grassTexture));
    entities.push_back(Entity(Vector2f(30, 0), grassTexture));
    entities.push_back(Entity(Vector2f(30, 30), grassTexture));
    entities.push_back(Entity(Vector2f(30, 60), grassTexture));
    entities.push_back(Entity(Vector2f(100, 50), grassTexture));

    bool gameRunning = true;

    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while (gameRunning)
    {
        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        if( frameTime > 0.25f )
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while ( accumulator >= timeStep )
        {
            while ( SDL_PollEvent(&event) )
            {
                if ( event.type == SDL_QUIT )
                {
                    gameRunning = false;
                    
                    std::cout << "Quit..." << std::endl;
                }
            }
            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;

        window.clear();

        for(Entity& e : entities)
        {
            window.render(e);
        }

        std::cout << window.getRefreshRate() << std::endl;

        window.display();

        int frameTicks = SDL_GetTicks() - startTicks;

        if ( frameTicks < 1000 / window.getRefreshRate())
        {
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        }
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}