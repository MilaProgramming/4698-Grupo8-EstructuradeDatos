//[11:10 AM] MSc. EDGAR FERNANDO SOLIS ACOSTA

#include <iostream>
#include <cstring>

void decimaBinario(int,char[]);

void decimaBinario(int val,char cad[]){
    if(val>=1){
        decimaBinario(val/2,cad);
        strcpy(cad,itoa((val%2),cad,10));
    }
strcat(cad,"\0");
//printf("%s",cad);
}

int main(int argc, char** argv) {

        char cad[10];
        decimaBinario(124,cad);
        printf("%s",cad);

        return 0;
}