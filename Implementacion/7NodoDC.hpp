/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#pragma once

template <typename T>

    class NodoDCM{
        private:
            T valor;
            NodoDCM* anterior;
            NodoDCM* siguiente;
        public:
        
            NodoDCM(T v){
                this->valor = v;
            }

            NodoDCM(){}

            ~NodoDCM(){
                delete anterior;
                delete siguiente;
            }

            void setValor(T v){
                this -> valor = v;
            }

            T getValor(){
                return this->valor;
            }

            void setAnterior(NodoDCM* ante){
                this -> anterior = ante;
            }

            void setSiguiente(NodoDCM* sig){
                this -> siguiente = sig;
            }

            NodoDCM* getAnterior(){
                return this-> anterior;
            }

            NodoDCM* getSiguiente(){
                return this -> siguiente;
            }

    };