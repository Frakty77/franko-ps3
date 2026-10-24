#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0) {
        printf("Błąd inicjalizacji SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Franko PS3 Engine",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event e;

    // Glowna petla gry
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            else if (e.type == SDL_CONTROLLERBUTTONDOWN) {
                // Wyjdz z gry po wcisnieciu przycisku START na padzie
                if (e.cbutton.button == SDL_CONTROLLER_BUTTON_START) {
                    running = false;
                }
            }
        }

        // Tlo dla klimatu Franko - ciemny fiolet / retro styl
        SDL_SetRenderDrawColor(renderer, 40, 20, 50, 255);
        SDL_RenderClear(renderer);

        // Wyświetl klatkę
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
