#include "../general.h"

typedef struct nodo_pila {
    elemento dato;
    struct nodo_pila * abajo;
} nodo_pila;

typedef struct pila {
    struct nodo_pila * top;
    struct nodo_pila * bottom;
    int size;
} pila;

// Métodos de creación / destrucción
void initialize_pila (pila * p);
void destroy_pila (pila * p);
// Métodos de modificación
void push (pila * p, elemento e);
void pop (pila * p);
// Métodos de consulta
elemento top (pila * p);
elemento bottom (pila * p);
int size_pila (pila * p);
boolean empty_pila (pila * p);
// Métodos de debuggeo
void print_pila_direcciones (pila * p);
void print_pila_diagrama (pila * p);