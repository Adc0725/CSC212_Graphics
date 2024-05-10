#include <SDL.h>
#include <iostream>

// Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int RECT_WIDTH = 100;
const int RECT_HEIGHT = 80;

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Two Rectangles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Calculate positions for rendering rectangles at the center of the window
    int posX1 = (SCREEN_WIDTH - RECT_WIDTH) / 2;
    int posY1 = (SCREEN_HEIGHT - RECT_HEIGHT) / 2;

    int posX2 = (SCREEN_WIDTH - RECT_WIDTH) / 2;
    int posY2 = posY1 + RECT_HEIGHT; // Render rectangle2 below rectangle1

    // Main loop flag
    bool quit = false;
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render rectangles
        SDL_Rect rect1 = { posX1, posY1, RECT_WIDTH, RECT_HEIGHT };
        SDL_Rect rect2 = { posX2, posY2, RECT_WIDTH, RECT_HEIGHT };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(renderer, &rect1);
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
        SDL_RenderFillRect(renderer, &rect2);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
