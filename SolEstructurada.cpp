#include <iostream>
#include <cstring>

void decimaBinario(int, char*);

void decimaBinario(int val, char *cad){
    if(val >= 1){
        decimaBinario(val/2, cad);
                    //Avanzo en posicion
        itoa(val%2, cad + strlen(cad), 10);
    }
    strcat(cad,"\0");
}


