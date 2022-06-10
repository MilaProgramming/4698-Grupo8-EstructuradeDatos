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

#include "2ItoString.hpp"

/* Creando una clase llamada NodoDC. */
template <typename T>

    class NodoDC: public ToString{
        private:
            T valor;
            NodoDC* anterior;
            NodoDC* siguiente;
        public:


            /**
             * @param v
             */
            NodoDC(T v){
                this->valor = v;
            }

           /**
            * NodoDC() es un constructor que inicializa los punteros a NULL
            */
            NodoDC(){}

            /**
             * El destructor de la clase NodoDC
             */
            ~NodoDC(){
                delete anterior;
                delete siguiente;
            }

          
            /**
             * Establece el valor de la variable valor al valor del parámetro v.
             * 
             * Parameters
             * ----------
             * v : T
             * 	El valor que se almacenará en el nodo.
             */
            void setValor(T v){
                this -> valor = v;
            }

           
           /**
            * Devuelve el valor de la variable valor.
            * 
            * Returns
            * -------
            * 	El valor del nodo.
            */
            T getValor(){
                return this->valor;
            }

        
           /**
            * Esta función establece el valor del puntero anterior al valor del puntero ante
            * 
            * Parameters
            * ----------
            * ante : NodoDC
            * 	El nodo anterior
            */
            void setAnterior(NodoDC* ante){
                this -> anterior = ante;
            }   

           
            /**
             * Establece el siguiente nodo.
             * 
             * Parameters
             * ----------
             * sig : NodoDC
             * 	es el siguiente nodo
             */
            void setSiguiente(NodoDC* sig){
                this -> siguiente = sig;
            }


           /**
            * `NodoDC* getAnterior()` devuelve el nodo anterior
            * 
            * Returns
            * -------
            * 	El nodo anterior.
            */
            
            NodoDC* getAnterior(){
                return this-> anterior;
            }

           
           /**
            * *|CURSOR_MARCADOR|*
            * 
            * Returns
            * -------
            * 	El puntero al siguiente nodo.
            */
            NodoDC* getSiguiente(){
                return this -> siguiente;
            }

               /**
           * Devuelve el valor de la variable.
           * 
           * Returns
           * -------
           * 	El valor del nodo.
           */
            string toString(){
                return valor->toString();
            }
            

    };