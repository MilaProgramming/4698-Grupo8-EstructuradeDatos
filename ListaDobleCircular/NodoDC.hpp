#pragma once

template <typename T>

    class NodoDC{
        private:
            T valor;
            NodoDC* anterior;
            NodoDC* siguiente;
        public:
            NodoD(T v){
                this->valor = v;
            }

            NodoD(){}

            ~NodoD(){
                delete anterior;
                delete siguiente;
            }

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setAnterior(NodoDC* ante){
                this -> anterior = ante;
            }

            void setSiguiente(NodoDC* sig){
                this -> siguiente = sig;
            }

            NodoDC* getAnterior(){
                return this-> anterior;
            }

            NodoDC* getSiguiente(){
                return this -> siguiente;
            }

    };