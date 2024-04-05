#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "../diseno/diseno.h"

/*********************************************************
            Métodos de creación / destrucción
*********************************************************/
void initialize_pila (pila * p) {
    p->top = NULL;
    p->bottom = NULL;
    p->size = 0;
}

void destroy_pila (pila * p) {
    int size = p->size;
    for(int i=0; i<size; i++) {
        pop(p);
    }
}

/*********************************************************
                  Métodos de modificación
*********************************************************/
void push (pila * p, elemento e) {
    nodo_pila * nuevo_nodo = malloc(sizeof(nodo_pila));
    nuevo_nodo->abajo = p->top;
    nuevo_nodo->dato = e;

    p->top = nuevo_nodo;
    if (empty_pila(p)) {
        p->bottom = nuevo_nodo;
    }
    p->size++;
}

void pop (pila * p) {
    if (empty_pila(p)) {
        printf("\n\033[31mERROR. pop (pila * p): la pila est%c vac%ca\033[0m\n", 160, 161);
        exit(1);
    }
    nodo_pila * nodo_eliminar = p->top;
    p->top = nodo_eliminar->abajo;
    
    p->size--;
    if(empty_pila(p)) {
        p->bottom = NULL;
    }
    free(nodo_eliminar);
}

/*********************************************************
                    Métodos de consulta
*********************************************************/
elemento top (pila * p) {
    if (empty_pila(p)) {
        printf("\n\033[31mERROR. top (pila * p): la pila est%c vac%ca\033[0m\n", 160, 161);
        exit(1);
    }
    return p->top->dato;
}

elemento bottom (pila * p) {
    if (empty_pila(p)) {
        printf("\n\033[31mERROR. bottom (pila * p): la pila est%c vac%ca\033[0m\n", 160, 161);
        exit(1);
    }
    return p->bottom->dato;
}

int size_pila (pila * p) {
    return p->size;
}

boolean empty_pila (pila * p) {
    return p->size == 0;
}

/*********************************************************
                    Métodos de debuggeo
*********************************************************/
void print_pila_direcciones (pila * p) {
    imprimir_separador();

    colorForeground("magenta");
    printf("\tPILA\n\n");
    colorDefault();

    printf(" Size: ");
    colorForeground("magenta claro");
    printf("%d\n", p->size);
    colorDefault();
    if(!empty_pila(p)) {
        printf(" Top.\tvalor: ");
        colorForeground("magenta claro");
        printf("%-16d ", p->top->dato.valor);
        colorDefault();
        printf("direcci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->top);
        colorDefault();

        printf(" Bottom.valor: ");
        colorForeground("magenta claro");
        printf("%-16d ", p->bottom->dato.valor);
        colorDefault();
        printf("direcci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->bottom);
        colorDefault();
        printf("\n");
    } else {
        printf(" Top.\tdirecci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->top);
        colorDefault();

        printf(" Bottom.direcci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->bottom);
        colorDefault();
    }
    nodo_pila * aux = p->top;
    while(aux != NULL) {
        printf(" valor: ");

        // IMPRESIÓN DEPENDIENTE DEL TIPO DE DATO
        printf("%-16d ", aux->dato.valor);
        // ---------------------------------------

        printf("direcci%cn: ", 162);
        printf("%-16d ", aux);
        printf("siguiente: ");
        printf("%-16d\n", aux->abajo);
        aux = aux->abajo;
    }
    imprimir_separador();
}

void print_pila_diagrama (pila * p) {
    imprimir_separador();

    colorForeground("magenta");
    printf("\tPILA\n\n");
    colorDefault();

    printf(" Size: ");
    colorForeground("magenta claro");
    printf("%d\n", p->size);
    colorDefault();
    if(!empty_pila(p)) {
        printf(" Top.\tvalor: ");
        colorForeground("magenta claro");
        printf("%-16d ", p->top->dato.valor);
        colorDefault();
        printf("direcci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->top);
        colorDefault();

        printf(" Bottom.valor: ");
        colorForeground("magenta claro");
        printf("%-16d ", p->bottom->dato.valor);
        colorDefault();
        printf("direcci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->bottom);
        colorDefault();
        printf("\n");
    } else {
        printf(" Top.\tdirecci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->top);
        colorDefault();

        printf(" Bottom.direcci%cn: ", 162);
        colorForeground("magenta claro");
        printf("%d\n", p->bottom);
        colorDefault();
    }
    nodo_pila * aux = p->top;
    while(aux != NULL) {
        if(aux == p->top) {
            printf("   %c", 218);
            int i;
            for(i=0; i<18; i++)
                printf("%c", 196);
            printf("%c\n", 191);
        }

        // IMPRESIÓN DEPENDIENTE DEL TIPO DE DATO
        printf("   %c %16d %c ", 179, aux->dato, 179);
        // ---------------------------------------
        
        colorForeground("magenta claro");
        printf("<- ");
        colorDefault();
        printf("%-16d\n", aux);
        if(aux == p->bottom) {
            printf("  ");
            int i;
            for(i=0; i<22; i++)
                printf("%c", 205);
            printf("\n");
        } else {
            printf("   %c", 195);
            int i;
            for(i=0; i<18; i++)
                printf("%c", 196);
            printf("%c\n", 180);
        }
        aux = aux->abajo;
    }
    imprimir_separador();
}