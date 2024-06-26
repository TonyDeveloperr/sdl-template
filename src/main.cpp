#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "rendering/RenderWindow.hpp"


int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL_Init has failed: " << SDL_GetError() << std::endl;

    if (IMG_Init(IMG_INIT_PNG) < 0)
        std::cout << "IMG_Init has failed: " << IMG_GetError() << std::endl;

    RenderWindow window("TEMPLATE", 1280, 720);

    SDL_Texture* logoTexture = window.LoadTexture("./assets/sprites/crimson.png");
    if (logoTexture == nullptr)
    {
        std::cout << "Failed to load texture. Exiting..." << std::endl;
        window.CleanUp();
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    int windowWidth, windowHeight;
    SDL_GetWindowSize(window.GetWindow(), &windowWidth, &windowHeight);

    int textureWidth = 100;
    int textureHeight = 100;
    int posX = (windowWidth - textureWidth) / 2;
    int posY = (windowHeight - textureHeight) / 2;


    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.Clear();
        window.Render(logoTexture,posX, posY, textureWidth, textureHeight);
        window.Display();
        
    }

    window.CleanUp();
    SDL_Quit();
    IMG_Quit();

    return 0;
}
