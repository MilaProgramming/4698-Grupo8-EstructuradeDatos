#ifndef T2INGRESODATOS_H
#define T2INGRESODATOS_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

#include "t2ConversionInt.h"
#include "t2ConversionFloat.h"

class IngresoDatos{
    private:
        ConversionInt converInt;
        ConversionFloat converFloat;
        char det;
    public:
        IngresoDatos();  

        //metodo pincipal
        char *ingresoDatos(string str);

        //Sub metodos
        char *agregoChars(char *dato);
        bool unicoPunto(char c);
};

#endif  