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

    i -> funcionPrincipal("Ingrese sus datos: ");

    return 0;
}