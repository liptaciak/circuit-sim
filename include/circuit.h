#ifndef __circuit__
#define __circuit__

enum circuit_element_type_t {
    Resistor
};

struct circuit_element_t {
    enum circuit_element_type_t type;
    struct circuit_element_t** next;
};

void process_circuit_element(struct circuit_element_t* element);

#endif // __circuit__