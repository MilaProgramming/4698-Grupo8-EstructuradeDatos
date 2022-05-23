#include <iostream>
#include "Numero.h"
#include <algorithm>

Numero::Numero(int numeros[]){
    this -> nums = new int[sizeof(numeros)];
    std::copy(numeros, numeros + sizeof(numeros), this -> nums);
}

