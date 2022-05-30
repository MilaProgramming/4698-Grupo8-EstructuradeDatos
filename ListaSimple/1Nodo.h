#pragma once

#include <iostream>
using namespace std;

class Nodo{
    private:
        int valor;
        Nodo* nodo;
    public:
        Nodo(int v){
            this -> valor = v;
            this -> nodo = nullptr;
        } 

        Nodo();

        ~Nodo(){
            delete &nodo;
        }    

        void setValor(int v){
            this -> valor = v;
        }

        int getValor(){
            return this->valor;
        }

        void setNodo(Nodo* n){
            this -> nodo = n;
        }

        Nodo* getNodo(){
            return this-> nodo;
        }

};
