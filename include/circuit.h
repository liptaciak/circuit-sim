#ifndef __circuit__
#define __circuit__

enum circuit_element_type_t {
    CONDUCTOR,
    VSOURCE,
    ISOURCE,
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    DIODE
};

struct circuit_element_t {
    enum circuit_element_type_t type;

    // Used for rendering
    float x;
    float y;

    union {
        struct { }                     conductor;
        struct { float resistance; }   resistor;
        struct { float capacitance; }  capacitor;
        struct { float inductance; }   inductor;
        struct { float voltage_drop; } diode;
        struct { float voltage; }      vsource;
        struct { float current; }      isource;
    };

    void (*draw)(struct circuit_element_t* element);
    struct circuit_element_t** next;
};

struct circuit_t {
    struct circuit_element_t* head;
    struct circuit_element_t* elements;
    size_t num_elements;
};

void process_circuit_element(struct circuit_element_t* element);

#endif // __circuit__