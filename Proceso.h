#include <iostream>
#include "1Pila.hpp"
#include <conio.h>
#include <string>
#include <cstring>
#include "Regex.cpp"

using namespace std;
#pragma once
   
class Proceso{
    private:
        Pila<string> *infija = new Pila<string>();
        Pila<string> *postfija = new Pila<string>();
        Pila<string> *prefija = new Pila<string>();

    public:

    Proceso(){
    }

    void evaluarPostfija();

    ~Proceso(){
        free(this);
    }

    Pila<string> *getInfija();
    void setInfija(Pila<string> *i);

    Pila<string> *getPostfija();
    void setPostfija(Pila<string> *post);

    Pila<string> *getPrefija();
    void setPrefija(Pila<string> *pre);

    void recibirExpresion();

    void convertirPostfija();

    void convertirPrefija();


};