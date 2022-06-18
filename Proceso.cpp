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
     * La función recibe una cadena del usuario, luego usa una expresión regular para dividir la cadena en tokens
     * y luego empuja esos tokens en una pila una cadena del usuario. Despues, la pila de cadenas se empuja a otra pila, que 
     * luego se imprime
     * @return un valor booleano.
     */
    bool Proceso::recibirExpresion(){

        string input{"0"};

       /* Obtener la entrada del usuario. */
        getline(cin,input);
        reemplazoSignos(input);

        if(buscoSignos(input)){

            
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
                reemplazoMenos(input);
                cout << input <<endl;
                //infija->imprimirT();
                return true;
            }else{
                cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
            }

        }else{
            cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis2"<<endl;
        }

        return false;
    }

    void Proceso::convertirPostfija(){

        Nodo<string> *it = infija->getPrimero();
        Pila<string> *conversion = new Pila<string>();

       /* Iterando a través de la expresión de infijo y empujando los tokens a una expresión de sufijo. */
        while(it != nullptr){

            string token{it->getValor()};

            if(r->esUnNumero(token)){
                postfija ->push(token);
                it = it->getNodo();
            }else{

                //Operador actual
                int op{operadores(token)};

                
                //Tope de la pila conversion. Que tiene los operandos
                string tope; //Tope de la pila de operadores.
                int pConversion; //No. de operador identificado.

                if(!(conversion->estaVacia())){
                    string tope{conversion->tope()};
                    int pConversion{operadores(conversion->tope())};
                }else{
                    string tope{"!"};
                    int pConversion{0};
                }

                //Prioridades de los operadores respectivos
                int p1{prioridades(op)};
                int p2{prioridades(pConversion)};

                
                
               it = it->getNodo();
            }
        
        }
    }



    int Proceso::operadores(const string &a){

        if(r->esUnMas(a)){
            return 1;
        }else if(r->esUnMenos(a)){
            return 2;
        }

        return 0;
    }

    int Proceso::prioridades(int operador){

        if(operador == 1 || operador == 2){
            return pSumaResta();
        }

        return 0;
    }

    /**
     * Devuelve el valor de la variable numero.
     * 
     * @return El valor devuelto es el valor de la variable numero.
    */
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
    
    void Proceso::reemplazaString(string& subject, const string& search, const string& replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }

    void Proceso::reemplazoSignos(string& str){
        reemplazaString(str, "(-", "(~");
    }

    void Proceso::reemplazoMenos(string& str){
        reemplazaString(str, "~", "-");
    }

    bool Proceso::buscoSignos(string& str){

        if (str.find("++") != string::npos) {
            return false;
        }else if(str.find("--") != string::npos){
            return false;
        }else if(str.find("-+") != string::npos){
            return false;
        }else if(str.find("+-") != string::npos){
            return false;
        }

        return true;
    }