#include <SDL3/SDL.h>
#include <emscripten/emscripten.h>

SDL_Window* window;
SDL_Renderer* renderer;

void main_loop(void* arg) {
    SDL_Texture* tex = (SDL_Texture*)arg;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Vertex verts[3] = {
        {{400.0f, 225.0f}, {255, 0, 0, 254}, {0,0}},
        {{300.0f, 400.0f}, {255, 0, 0, 254}, {0,0}},
        {{500.0f, 400.0f}, {255, 0, 0, 254}, {0,0}}
    };

    int indices[3] = {0, 1, 2};
    SDL_RenderGeometry(renderer, tex, verts, 3, indices, 3);
    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Circuit Simulator", 800, 600, 0);
    renderer = SDL_CreateRenderer(window, NULL);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    SDL_Texture* tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 1, 1);
    Uint32 white = 0xFFFFFFFF;
    SDL_UpdateTexture(tex, NULL, &white, sizeof(Uint32));

    emscripten_set_main_loop_arg(main_loop, tex, 0, 1);
    return 0;
}