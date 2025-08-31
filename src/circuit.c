#include <SDL3/SDL.h>
#include <emscripten/emscripten.h>

SDL_Window* window;
SDL_Renderer* renderer;

void main_loop(void* arg) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Vertex verts[3];
    verts[0].position.x = 400.0f; 
    verts[0].position.y = 100.0f; 
    verts[0].color.r = 255;
    verts[0].color.g = 0; 
    verts[0].color.b = 0; 
    verts[0].color.a = 255;
    
    verts[1].position.x = 300.0f; 
    verts[1].position.y = 400.0f; 
    verts[1].color.r = 255; 
    verts[1].color.g = 0; 
    verts[1].color.b = 0; 
    verts[1].color.a = 255;

    verts[2].position.x = 500.0f; 
    verts[2].position.y = 400.0f; 
    verts[2].color.r = 255; 
    verts[2].color.g = 0; 
    verts[2].color.b = 0; 
    verts[2].color.a = 255;

    int indices[3] = {0, 1, 2};
    SDL_RenderGeometry(renderer, NULL, verts, 3, indices, 3);
    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("SDL3 Triangle", 800, 600, 0);
    renderer = SDL_CreateRenderer(window, NULL);

    emscripten_set_main_loop_arg(main_loop, renderer, 0, 1);
    return 0;
}