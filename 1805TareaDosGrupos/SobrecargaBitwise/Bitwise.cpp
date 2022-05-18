#include "Bitwise.hpp"
#include <cstdio>

int main(){

    Bitwise<int, 0> uno(7);

    uno.imprimir();

    Bitwise<int, 0> nuevo;

    nuevo = ~uno;

    nuevo.imprimir();
    
    return 0;
}