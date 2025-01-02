#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "utils.h"
using namespace std;

// Variables
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void DrawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void DrawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // Horizontal distance from center
            int dy = radius - h; // Vertical distance from center
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}

void DrawPoints(SDL_Renderer *renderer, pair<int, int> *Points, int p_Amount)
{
    for (int i = 0; i < p_Amount; i++)
    {
        DrawCircle(renderer, Points[i].first, Points[i].second, 6);
    }
}

int main()
{

    int pointsAmount;

    // Ask for the size of the array
    cout << "Enter the size of the array: ";
    cin >> pointsAmount;

    pair<int, int> Points[pointsAmount];
    for (int i = 0; i < pointsAmount; i++)
    {
        Points[i] = getRandomPoint(WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    //************* Window init
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Round Dot Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window)
    {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool running = true;
    SDL_Event event;

    while (running)
    {
        // Handle events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        // Draw the circle
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color

        DrawPoints(renderer, Points, pointsAmount);

        DrawLine(renderer, 200, 200, 300, 300);

        // Present the renderer
        SDL_RenderPresent(renderer);
        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
