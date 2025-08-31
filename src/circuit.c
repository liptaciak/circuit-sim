#include <SDL3/SDL.h>
#include <emscripten/emscripten.h>

SDL_Window* window;
SDL_Renderer* renderer;

void process_circuit_element(struct circuit_element_t* element) {
    // Process the circuit element (e.g., update its state, render it, etc.)
}

void main_loop(void* arg) {
    struct circuit_t state = (struct circuit_t*)arg;

    process_circuit_element(state.head);
}

int main() {
    struct circuit_element_t source;
    struct circuit_element_t resistor;

    source.type = VSOURCE;
    source.x = 100.0f;
    source.y = 100.0f;
    source.vsource.voltage = 5.0f;
    source.draw = NULL;

    resistor.type = RESISTOR;
    resistor.x = 200.0f;
    resistor.y = 200.0f;
    resistor.resistor.resistance = 1000.0f;
    resistor.draw = NULL;

    struct circuit_element_t* source_next[] = { &resistor, NULL };
    source.next = source_next;

    struct circuit_element_t* resistor_next[] = { &source, NULL };
    resistor.next = resistor_next;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Circuit Simulator", 800, 600, 0);
    renderer = SDL_CreateRenderer(window, NULL);

    struct circuit_t state;
    
    state.head = &source;
    state.elements = &source;
    state.num_elements = 2;

    emscripten_set_main_loop_arg(main_loop, &state, 0, 1);
    return 0;
}