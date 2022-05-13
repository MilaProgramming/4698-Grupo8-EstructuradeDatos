#ifndef T2INGRESODATOS_H
#define T2INGRESODATOS_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#include "t2ConversionInt.h"
#include "t2ConversionFloat.h"

class IngresoDatos{
    private:
        ConversionInt converInt;
        ConversionFloat converFloat;
    public:
        IngresoDatos();  

        //metodo pincipal
        char *ingresoDatos(string str);

        //Sub metodos
        char *backspace(int i, char *dato);
        char *agregoChars(char *dato);
};

#endif  