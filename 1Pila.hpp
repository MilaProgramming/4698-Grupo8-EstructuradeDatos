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

            Nodo<T>* getPrimero(){
                return this->primero;
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
                if(longitud == 0){
                    cout<< "\nStack underflow"<<endl;
                }else if(longitud == 1){
                    valor = primero->getValor();
                    primero = nullptr;
                    ultimo = nullptr;
                    longitud--;
                    return valor;
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
                
                //cout<< "Entro funcion" <<endl;

                if(primero == nullptr) cout<<"\nStack underflow"<<endl;
                else{

                    //cout<< ultimo->getValor() <<endl;
                    //cout<< "Entro" <<endl;

                    Nodo<T> *n = primero;
                    Pila<T> *pNueva = new Pila<T>();

                    while(n != nullptr){
                        pNueva->push(n->getValor());
                        n = n->getNodo();
                    }

                    //cout<< pNueva->ultimo->getValor() <<endl;

                    Nodo<T> *np = pNueva->primero;
                    cout<<"\n";

                    while(np!=nullptr){
                        cout<< pNueva->pop() << " ";
                        np = np->getNodo();
                    }

                    //cout<< "Final" <<endl;
                }
            }

            void imprimirT(){
                
                if(primero == nullptr) cout<<"\nStack underflow"<<endl;
                else{

                    Nodo<T> *np = primero;

                    while(np!=nullptr){
                        cout<< np->getValor() << " ";
                        np = np->getNodo();
                    }
                    
                }
            }

            T tope(){
                return this->primero->getValor();
            }

            int getLongitud(){
                return this->longitud;
            }

    };    