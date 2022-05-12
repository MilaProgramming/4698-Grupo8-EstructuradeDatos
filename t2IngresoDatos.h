#ifndef T2INGRESODATOS_H
#define T2INGRESODATOS_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class IngresoDatos{
    private:

    public:
        IngresoDatos();  

        //metodo pincipal
        char *ingresoDatos(string str);

        //Sub metodos
        char *backspace(int i);
        char *agregoChars();
};

#endif  