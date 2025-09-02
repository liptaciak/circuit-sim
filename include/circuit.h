#ifndef __circuit__
#define __circuit__

/*
    enum circuit_stage_t {
        STAGE_COMPILE,
        STAGE_SIMULATE
    };
*/

enum circuit_element_type_t {
    CONDUCTOR,
    VSOURCE,
    ISOURCE,
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    DIODE
};

struct circuit_node_t {
    float voltage;
};

struct circuit_element_t {
    enum circuit_element_type_t type;

    /*
        float x;
        float y;
    */

    union {
        struct { }                     conductor;
        struct { float resistance; }   resistor;
        struct { float capacitance; }  capacitor;
        struct { float inductance; }   inductor;
        struct { float voltage_drop; } diode;
        struct { float voltage; }      vsource;
        struct { float current; }      isource;
    };

    struct circuit_node_t** nodes;
};

struct circuit_t {
    // enum circuit_stage_t current_stage;

    struct circuit_element_t* elements;
    size_t num_elements;
};

void process_circuit_element(struct circuit_element_t* element);

#endif // __circuit__