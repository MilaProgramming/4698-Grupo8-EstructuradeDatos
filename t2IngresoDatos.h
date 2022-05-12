#ifndef T2INGRESODATOS_H
#define T2INGRESODATOS_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class IngresoDatos{
    private:
        string str;

    public:
        IngresoDatos(string str);  

        char *ingresoDatos(string str);
};

#endif