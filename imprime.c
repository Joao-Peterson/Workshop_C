#include "imprime.h"

#include <stdio.h>

static int protegida = 0;

void imprime(char *string){
    printf("%s\n", string);
}

void set_protegida(int valor){
    if(valor <= 10000)
        protegida = valor;
}

int get_protegida(void){
    if(protegida <= 10000)
        return protegida;
}

int contador(void){
    
    static int i = 0;
    i++;
    return i;
}