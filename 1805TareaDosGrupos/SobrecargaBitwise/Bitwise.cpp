/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


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