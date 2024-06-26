#pragma once
#include <SDL.h>
#include <SDL_image.h>

class RenderWindow {
    public: 

    RenderWindow(const char* title, int w, int h);
    ~RenderWindow();
    SDL_Texture* LoadTexture(const char* filePath);
    SDL_Window* GetWindow();
    void CleanUp();
    void Clear();
    void Render(SDL_Texture* texture, int x, int y, int w, int h);
    void Display();

    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
};