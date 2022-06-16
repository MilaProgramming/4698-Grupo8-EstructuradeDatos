#include <iostream>
#include "Proceso.h"
using namespace std;
#pragma once

Pila<char>* Proceso::getIngreso(){
    return this->ingreso;
}

void Proceso::setIngreso(Pila<char> *i) {
    this ->ingreso = i;
}

void Proceso::recibirExpresion(){

    string input{"0"};

    cin >> input;

    int n = input.length();
    char *aux = new char[n+1];

    strcpy(aux, input.c_str());

    for (int i = 0; i < n; i++){
        ingreso->push(aux[i]);
    }    

    //ingreso->imprimir();
    delete &input;
    delete &aux;
}