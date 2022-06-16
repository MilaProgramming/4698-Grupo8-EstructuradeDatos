#include <iostream>
#include "1Pila.hpp"
#include <conio.h>
#include <string>
#include <cstring>
using namespace std;
#pragma once
   
class Proceso{
    private:
        Pila<char> *ingreso = new Pila<char>();

    public:

    Proceso(){
    }

    ~Proceso(){
        free(this);
    }

    Pila<char> *getIngreso();
    void setIngreso(Pila<char> *i);

    void recibirExpresion();




};