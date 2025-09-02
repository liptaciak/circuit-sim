#include <SDL3/SDL.h>
#include <emscripten/emscripten.h>

#include "circuit.h"

SDL_Window* window;
SDL_Renderer* renderer;

void simulate_circuit(struct circuit_t* circuit) {
    for (size_t i = 0; i < circuit->num_elements; i++) {
        switch (circuit->elements[i].type) {
            case CONDUCTOR: {
                // Just an example, i will rewrite this.

                struct circuit_node_t* node_a = circuit->elements[i].nodes[0];
                struct circuit_node_t* node_b = circuit->elements[i].nodes[1];

                if (node_a->voltage != 0.0f) {
                    node_b->voltage = node_a->voltage;
                } else if (node_b->voltage != 0.0f) {
                    node_a->voltage = node_b->voltage;
                }
                break;
            }
            case VSOURCE:
                break;
            case ISOURCE:
                break;
            case RESISTOR:
                break;
            case CAPACITOR:
                break;
            case INDUCTOR:
                break;
            case DIODE:
                break;
        }
    }
    return;
}

void render_circuit(struct circuit_t* circuit) {
    return;
}

void main_loop(void* arg) {
    struct circuit_t* circuit_state = (struct circuit_t*)arg;

    /*
        switch (...)
    */

    simulate_circuit(circuit_state);
    render_circuit(circuit_state);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Circuit Simulator", 800, 600, 0);
    renderer = SDL_CreateRenderer(window, NULL);

    struct circuit_t circuit_state = { NULL, 0 };
    emscripten_set_main_loop_arg(main_loop, &circuit_state, 0, 1);

    return 0;
}