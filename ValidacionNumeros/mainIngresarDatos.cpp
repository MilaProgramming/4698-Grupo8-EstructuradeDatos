//!Funcion ingresar datos. Incluye Conversion.hpp e IngresoDatos.hpp
//!El tipo esta hecho para ser <int, float>

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Conversion.hpp"
#include "IngresoDatos.hpp"

using namespace std;

int main(){
    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();

    //i -> funcionPrincipal("Ingrese sus datos: ");
    i -> funcionPrincipalLetras("Ingrese letritas: ");
    i ->funcionPrincipalEnteros("Ingrese numeritos enteros: ");
    i->funcionPrincipalFlotantes("Ingrese numeritos flotantes: ");
    
    return 0;
}