/**
 * A keyword const define uma variavél que será estáticamente compilada,
 * sendo sua informação embarcada no binário final.
 * 
 * Já a keyword static define uma variavél que pertence unica
 * e exclusivamente a uma unidade de tradução / bloco
 * 
 * Note que uma não é o inverso da outra.
 * 
 * Extern define uma variavél presente em outra unidade de tradução sem 
 * declaração prévia. Neste se sentido ela expõe uma variavél enquanto 
 * static a esconde, então ambas podem ser consideradas opostas, porém
 * extern não pode ser usada em conjunto com static.
 * 
 */

void funcao(void){
    static int i = 0;
    i++;
    printf("i: %d\n", i);
}

int main(){

    funcao();
    funcao();
    funcao();

    return 0;
}

// stdout:
// i: 1
// i: 2
// i: 3


/// modulo_extra.c
int i = 42;

/// main.c
extern int i;

void main(){
    printf("i: %d\n", i);

    return 0;
}

// stdout:
// i: 42