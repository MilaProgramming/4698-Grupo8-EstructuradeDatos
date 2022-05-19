#include <iostream>
#include <cstring>
#include "SolEstructurada.cpp"

int main(){

    char *cad = new char[10];
    cad[0] = '\0';
    decimaBinario(124, cad);

    printf("%s ", cad);

    return 0;
}