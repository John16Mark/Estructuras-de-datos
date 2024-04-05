#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../../libs/TAD/pila.h"

boolean analizar_parentesis(char * expr);
void convertir_a_postfijo (char * expr_original, char * expr_postfija);
void asignar_incognitas (char * expr, double * incognitas);
double resolver (char * expr_postfija, double * incognitas);
boolean es_numero (char c);
boolean es_operador (char c);
boolean tiene_mayor_igual_precedencia (char a, char b);
int precedencia (char c);

int main (int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("\n\033[91m ERROR: El programa debe ejecutarse con un argumento, el argumento debe ser la expresi%cn a evaluar.\n", 162);
        printf("  Ejemplo: main.exe \"A+B+(C*D)\"\033[0m\n");
        exit(1);
    }
    char * expr_original;
    expr_original = argv[1];
    if (expr_original == NULL) {
        printf("\n\033[91m ERROR: no se asign%c correctamente la expresi%cn.\033[0m\n", 162, 162);
        exit(1);
    }

    printf("\n\033[96m Expresi%cn infija: \033[0m%s\n", 162, expr_original);
    if(!analizar_parentesis(expr_original)) {
        printf("\n\033[91m Error: par%cntesis incorrectos.\033[0m\n", 130);
        exit(1);
    }

    printf("\n\033[92m Par%cntesis correctos.\033[0m\n", 130);
    
    char * expr_postfija = (char *) malloc((int)(strlen(expr_original) * sizeof(char) * 1.5));
    convertir_a_postfijo(expr_original, expr_postfija);
    printf("\n\033[96m Expresi%cn postfija: \033[0m%s\n", 162, expr_postfija);
    
    double incognitas[26];
    asignar_incognitas(expr_original, incognitas);

    printf("\n \033[92mResultado: \033[0m%lf", resolver(expr_postfija, incognitas));
    return 0;
}

boolean analizar_parentesis(char * expr) {
    pila stack;
    initialize_pila(&stack);
    elemento e = {1};

    for (int i=0; i<strlen(expr); i++) {
        char c = expr[i];
        if (c == '(')
            push(&stack, e);
        else if (c == ')') {
            if (empty_pila(&stack)) {
                return FALSE;
            }
            pop(&stack);
        }
    }

    if (!empty_pila(&stack)) {
        destroy_pila(&stack);
        return FALSE;
    }
    else {
        destroy_pila(&stack);
        return TRUE;
    }
}

void convertir_a_postfijo (char * expr_original, char * expr_postfija) {
    pila stack;
    elemento e;
    initialize_pila(&stack);
    int indice_postfija = 0;

    expr_postfija[0]='\0';
    int tam = strlen(expr_original);
    for (int i=0; i<tam; i++) {
        char c = expr_original[i];

        if (c >= 'A' && c <= 'Z') {
            expr_postfija[indice_postfija] = c;
            indice_postfija++;

        } else if (es_numero(c)) {
            if (indice_postfija > 0 && es_numero(expr_postfija[indice_postfija-1])) {
                expr_postfija[indice_postfija] = ' ';
                indice_postfija++;
            }
            expr_postfija[indice_postfija] = c;
            indice_postfija++;
            while (i+1<tam && (es_numero(expr_original[i+1]) || expr_original[i+1] == '.')) {
                i++;
                expr_postfija[indice_postfija] = expr_original[i];
                indice_postfija++;
            }

        } else if (es_operador(c)) {
            if (empty_pila(&stack)) {
                e.valor = c;
                push(&stack, e);
            } else {
                while (!empty_pila(&stack) && tiene_mayor_igual_precedencia(top(&stack).valor, c)) {
                    expr_postfija[indice_postfija] = top(&stack).valor;
                    pop(&stack);
                    indice_postfija++;
                }
                e.valor = c;
                push(&stack, e);
            }

        } else if (c == '(') {
            e.valor = c;
            push(&stack, e);

        } else if (c == ')') {
            while (top(&stack).valor != '(') {
                expr_postfija[indice_postfija] = top(&stack).valor;
                pop(&stack);
                indice_postfija++;
            }
            pop(&stack);
        }
        
    }
    while (!empty_pila(&stack)) {
        expr_postfija[indice_postfija] = top(&stack).valor;
        pop(&stack);
        indice_postfija++;
    }
    expr_postfija[indice_postfija] = '\0';
    destroy_pila(&stack);
}

void asignar_incognitas (char * expr, double * incognitas) {
    for (int i=0; i<26; i++) {
        incognitas[i] = 0.0/0.0;
    }

    int tam = strlen(expr);
    int contador = 0;
    for (int i=0; i<tam; i++) {
        if (expr[i] >= 'A' && expr[i] <= 'Z') {
            incognitas[expr[i]-'A'] = 0;
            contador++;
        }
    }
    if (contador == 0)
        return;
    
    printf("\n \033[92mAsignar valores a las variables: \033[0m\n\n");

    for (int i=0; i<26; i++) {
        if (!isnan(incognitas[i])) {
            printf("   Valor de %c: ", i+'A');
            scanf("%lf", &incognitas[i]);
            if (isnan(incognitas[i])) {
                printf("\n\033[91m Error: valor no v%clido.\033[0m\n", 160);
                exit(1);
            }
        }
    }
    return;
}

double resolver (char * expr_postfija, double * incognitas) {
    
}

boolean es_numero (char c) {
    return c >= '0' && c <= '9';
}

boolean es_operador (char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

boolean tiene_mayor_igual_precedencia (char a, char b) {
    return precedencia(a) >= precedencia(b);
}

int precedencia (char c) {
    switch (c) {
    case '^':
        return 3;
        break;

    case '*':
    case '/':
        return 2;
        break;
    
    case '+':
    case '-':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}