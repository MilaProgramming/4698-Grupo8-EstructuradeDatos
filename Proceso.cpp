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
     * Recibe una cadena del usuario, luego usa una expresión regular para dividir la cadena en tokens
     * y luego empuja esos tokens en una pila
     */
    bool Proceso::recibirExpresion(){

        string input{"0"};

       /* Obtener la entrada del usuario. */
        getline(cin,input);

        int longitud = input.length();

        Pila<string> *fragmento= r->fragmento(input);

        /* Empujando los valores de la pila de fragmentos en la pila infija. */
        Nodo<string> *n = fragmento->getPrimero();
        while(n != nullptr){        
            infija->push(n->getValor());
            n = n->getNodo();
        }

        /* Comprobando si la longitud de la entrada es la misma que la longitud de la pila. */
        if(r->compararLongitudes(longitud)){
            cout<< "\nExpresion leida con exito"<<endl;
            infija->imprimirT();
            return true;
        }else{
            cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
        }

        //infija->imprimirT();
        return false;
    }

    void Proceso::convertirPostfija(){

        Nodo<string> *it = infija->getPrimero();
        Pila<string> *conversion = new Pila<string>();

        while(it != nullptr){



            it = it->getNodo();
        }
    }


    int Proceso::pNumero(){
        return 0;
    }

    int Proceso::pSumaResta(){
        return 5;
    }

    int Proceso::pMultiplicacionDivision(){
        return 4;
    } 

    int Proceso::pExponenteRaiz(){
        return 3;
    }

    int Proceso::pTrigonometricasLog(){
        return 2;
    }

    int Proceso::pParentesis(){
        return 1;
    }



    