#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int w, int h)
    : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "Window failed to init. Error:" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout << "Renderer failed to init. Error:" << SDL_GetError() << std::endl;
    }
}

RenderWindow::~RenderWindow()
{
    CleanUp();
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (texture == nullptr)
    {
        std::cout << "Failed to load texture '" << filePath << "'. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::CleanUp()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::Render(SDL_Texture* texture, int x, int y, int w, int h)
{
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = w;
    dstRect.h = h;

    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}

void RenderWindow::Display()
{
    SDL_RenderPresent(renderer);
}

SDL_Window* RenderWindow::GetWindow()
{
    return window;
}