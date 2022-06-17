#include <iostream>
#include "Proceso.h"
using namespace std;
#pragma once

    Pila<string>* Proceso::getInfija(){
        return this->infija;
    }

    void Proceso::setInfija(Pila<string> *i) {
        this ->infija = i;
    }

    Pila<string> *Proceso::getPostfija(){
        return postfija;
    }

    void Proceso::setPostfija(Pila<string> *post) {
        postfija = post;
    }

    Pila<string> *Proceso::getPrefija(){
        return prefija;
    }

    void Proceso::setPrefija(Pila<string> *pre) {
        prefija = pre;
    }

    /**
    * Recibe una cadena del usuario, la convierte en una matriz de caracteres y empuja cada carácter en
    * una pila
    */
    void Proceso::recibirExpresion(){

        string input{"0"};

        Regex *r = new Regex();
        cin >> input;

        Pila<string> *fragmento= r->fragmento(input);
        // cout<< "cola"<<endl;
        // fragmento->imprimir();
        // cout<<"antes del segundo imprimir"<<endl;
        // fragmento->imprimir();
        // cout<<"hago cosas despues"<<endl;

        Nodo<string> *n = fragmento->getPrimero();
        //cout<< n->getValor()<<endl; 
        while(n != nullptr){
            //cout<< n->getValor()<<endl<<endl;           
            infija->push(n->getValor());
            n = n->getNodo();
        }

        infija->imprimirT();
    }

    void Proceso::convertirPostfija(){

        Nodo<string> *it = infija->getPrimero();
        Pila<string> *conversion = new Pila<string>();

        while(it != nullptr){



            it = it->getNodo();
        }
    }


    void Proceso::convertirPrefija(){
        
    }


    