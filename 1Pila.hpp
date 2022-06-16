//!Plantilla de una lista Simple. Incluye nodo.hpp

#include <iostream>
using namespace std;
#include "1Nodo.hpp"
#pragma once

template <typename T>
    class Pila{

        private:
            Nodo<T> *primero = nullptr;
            Nodo<T> *ultimo = nullptr;
            int longitud=0;

        public:
            Pila(){
            }

            ~Pila(){
                free(this);
            }

            bool estaVacia(){
                return primero == nullptr;
            }

            void push(T v){

                Nodo<T> *n = new Nodo<T>(v);

                if(primero == nullptr){
                    primero = ultimo = n;
                }else{
                    n->setNodo(primero);
                    primero = n;
                }
                longitud++;

            }

            T pop(){

                T valor;
                if(primero == nullptr){
                    cout<< "\nStack underflow"<<endl;
                }else{
                    Nodo<T> *n = primero->getNodo();
                    valor = primero->getValor();
                    primero->~Nodo();
                    primero = n;
                    longitud--;
                }

                return valor;
            }

            void imprimir(){

                if(primero == nullptr) cout<<"\nStack underflow"<<endl;
                else{

                    Nodo<T> *n = primero;

                    Pila<T> *pNueva = new Pila<T>();

                    while(n != nullptr){
                        pNueva->push(n->getValor());
                        n = n->getNodo();
                    }

                    Nodo<T> *np = pNueva->primero;

                    cout<<"\n";

                    while(!(pNueva->estaVacia())){
                        cout<< pNueva->pop() << " ";
                        np = np->getNodo();
                    }

                    np->~Nodo();
                    pNueva->~Pila();

                }
            }

    };    