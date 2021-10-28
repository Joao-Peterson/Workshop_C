#include <stdio.h>
#include <stdint.h>
#include "imprime.h"

int calcula_temperatura_int(void);

#define calcula_temperatura(type) (type)calcula_temperatura_int()


int main(){

    funcao_critica();

    int temperatura = calcula_temperatura(int);

    // imprime("Hello world!");

    // contador();
    // contador();
    // contador();
    // contador();

    // printf("%d\n", contador());

    return 0;
}