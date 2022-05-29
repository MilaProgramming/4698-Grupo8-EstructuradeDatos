#include <iostream>
#include "Lista.h"

ListaEnlazada::ListaEnlazada(){

}

bool ListaEnlazada::estaVacio(){
    return this -> primero == nullptr;
}

void ListaEnlazada::agregarFinal(int nuevo){
    Nodo *n = new Nodo(nuevo);

    if(estaVacio())
        primero = ultimo = n;
    else{
        ultimo -> setNodo(n);
        ultimo = n;
    }
}

void ListaEnlazada::agregarInicio(int nuevo){
    Nodo *n = new Nodo(nuevo);

    if(estaVacio())
        primero = ultimo = n;
    else{
        n -> setNodo(primero);
        primero = n;
    }
}



void ListaEnlazada::imprimirCabeza(){
    Nodo *nimpreso;
    nimpreso = primero;

    while( nimpreso != nullptr){
        cout<< nimpreso -> getValor() << " ";
        nimpreso = nimpreso->getNodo();
    }
}