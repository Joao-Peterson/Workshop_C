/**
 * Use a key word volatile quando a variavél será alterada de forma externa
 * ao ponto de entrada main(), por exemplo: rotinas de interrupção ISR, 
 * código em outros processos e etc.
 */

volatile int counter;

void ISR_gpio_pin_C2(void *vector){
    
    if(counter < 100)
        counter++;
    else
        counter = 0;
        
}

int main(){

    counter = 0;

    while(1){

        // CÓDIGO 

        if(counter > 50){

            // CÓDIGO 

        }

    }

    return 0;
}