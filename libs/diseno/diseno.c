#include <stdio.h>
#include <string.h>
#include "diseno.h"

void imprimir_separador() {
    int i;
    printf("\n");
    for(int i=0; i<81; i++) {
        printf("%c", 205);
    }
    printf("\n");
}

void colorForeground(char *color){
	if(strcmp(color,"negro") == 0){
		printf("\033[30m");
	}
	else if(strcmp(color,"rojo") == 0){
		printf("\033[31m");
	}
    else if(strcmp(color,"verde") == 0){
		printf("\033[32m");
	}
    else if(strcmp(color,"amarillo") == 0){
		printf("\033[33m");
	}
	else if(strcmp(color,"azul") == 0){
		printf("\033[34m");
	}
	else if(strcmp(color,"magenta") == 0){
		printf("\033[35m");
	}
    else if(strcmp(color,"cian") == 0){
		printf("\033[36m");
	}
	else if(strcmp(color,"gris claro") == 0){
		printf("\033[37m");
	}
	else if(strcmp(color,"gris oscuro") == 0){
		printf("\033[90m");
	}
	else if(strcmp(color,"rojo claro") == 0){
		printf("\033[91m");
	}
    else if(strcmp(color,"verde claro") == 0){
		printf("\033[92m");
	}
    else if(strcmp(color,"amarillo claro") == 0){
		printf("\033[93m");
	}
    else if(strcmp(color,"azul claro") == 0){
		printf("\033[94m");
	}
	else if(strcmp(color,"magenta claro") == 0){
		printf("\033[95m");
	}
	else if(strcmp(color,"cian claro") == 0){
		printf("\033[96m");
	}
	else if(strcmp(color, "blanco") == 0){
		printf("\033[97m");
	}
}

void colorDefault() {
    printf("\033[0m\033[40m");
}