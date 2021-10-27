/**
 * Define um pedaço de memória do mesmo tamanho do maior membro
 * onde todos os membros podem acessar o memso espaço de memória.
 */

/*
*-------------*
|     int     |
| 00 00 00 01 | 
*-------------*
| b1 b2 b3 b4 |
| 00 00 00 01 | 
*-------------*
*/


typedef unsigned char uint8_t; 

typedef union{
    int inteiro;
    uint8_t bytes[4];
}my_union;

typedef struct{
    int inteiro;
    uint8_t bytes[4];
}my_struct;

void main(){
    printf("size union: %d\n", sizeof(my_union));
    printf("size struct: %d\n", sizeof(my_struct));

    my_union mem = {.inteiro = 1};

    for(int i = 0; i < 4; i++)
        printf("byte: %d\n", mem.bytes[i]);

    return 0;
}

// stdout:
// size union: 4
// size struct: 8
// byte: 0
// byte: 0
// byte: 0
// byte: 1