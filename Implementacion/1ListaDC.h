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

  /**
    * ListaDobleC implementation
    */
   
#pragma once

#include <iostream>
#include "1NodoDC.h"
#include "2IInsertar.h"
#include "2IEliminar.h"
#include "2IBuscar.h"
#include "2ItoString.h"

using namespace std;

template <typename T>
    class ListaDobleC: public Insertar<T>, public Eliminar<T>, public Buscar<T>, public ToString{

        private:
            NodoDC<T> *primero = nullptr;
            NodoDC<T> *ultimo = nullptr;
            int longitud;

            /**
             * @param indice
             * @return indiceOFL
             */
            bool indiceOFL(int indice){
                return indice >= longitud  || indice < 0;
            }

        public:
   
            /**
             * @return bool
             */
            bool estaVacio ListaDobleC::estaVacio() {
                    return primero == nullptr;
            }

            ListaDobleC(){
                longitud = 0;
            }

            ~ListaDobleC(){
                free(primero);
                free(ultimo);
            }

            /**
             * @param v
             * @return insertarInicio
             */
            void insertarInicio(T v){

                    if(longitud == 0){
                        NodoDC<T> *nuevo = new NodoDC<T>(v);
                        primero = ultimo = nuevo;
                        longitud++;
                    }else{

                        NodoDC<T> *nuevo = new NodoDC<T>(v);

                        //Conecto direcciones del nuevo nodo
                        nuevo->setAnterior(ultimo);
                        nuevo->setSiguiente(primero);
                        //Recorro direccion del nodo existente
                        primero->setAnterior(nuevo);
                        //Asigno nuevos iteradores
                        primero = nuevo;

                        longitud++;
                    }
                
            }

            /**
             * @param v
             * @return insertarFinal
             */            
            void insertarFinal(T v){

               
                 if(longitud == 0){
                        NodoDC<T> *nuevo = new NodoDC<T>(v);
                        primero = ultimo = nuevo;
                        longitud++;
                    }else{

                    NodoDC<T> *nuevo = new NodoDC<T>(v);

                        //Conecto direcciones del nuevo nodo
                        nuevo->setAnterior(ultimo);
                        nuevo->setSiguiente(primero);
                        //Recorro direccion del nodo existente
                        ultimo->setSiguiente(nuevo);
                        //Asigno nuevos iteradores
                        ultimo = nuevo;

                    longitud++;
                    }              
            }

            /**
             * @param v
             * @param indice
             * @return insertar
             */
            void insertar(T v, int indice){

                if(indiceOFL(indice)){
                    cout <<"La lista no posee tantos elementos, o no es de longitud negativa" <<endl;
                    return;
                }else{
                    
                    if(indice == 0){
                        insertarInicio(v);
                    
                    }else{    

                        NodoDC<T> *nuevo = new NodoDC<T>(v);
                        NodoDC<T> *iterador = primero;

                        while(indice != 0){
                            iterador = iterador->getSiguiente();
                            indice--;
                        }    
                        
                        //Conecto nodo nuevo en donde se solicito
                        nuevo->setAnterior(iterador->getAnterior());
                        nuevo->setSiguiente(iterador);

                        //Conecto los nodos de la lista al nodo nuevo
                        (iterador->getAnterior())->setSiguiente(nuevo);
                        iterador->setAnterior(nuevo);
                    }

                    longitud++;
                }
            }

            /**
             * @param v
             * @return insertar
             */
            void insertar(T v){
                if(longitud == 0){
                    NodoDC<T> *nuevo = new NodoDC<T>(v);
                    primero = ultimo = nuevo;
                    longitud++;
                }else cout<<"Cuidado. Su lista ya posee nodos" <<endl;
            }



            /**
             * @return eliminarInicio
             */
            void eliminarInicio(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{

                    if(primero == ultimo){
                        primero = ultimo = nullptr;
                    }else{
                        NodoDC<T> *segundo = primero->getSiguiente();
                        primero = nullptr; //Elimino referencia
                        primero = segundo;
                        segundo -> setAnterior(primero);    
                    }
                    
                    longitud--;
                }
            }
            

            /**
             * @return eliminarFinal
             */
            void eliminarFinal(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{
                    if(primero == ultimo){
                        primero = ultimo = nullptr;
                    }else{
                        NodoDC<T> *previo = ultimo->getAnterior();
                        ultimo = nullptr;
                        ultimo = previo;
                        ultimo->setSiguiente(primero);
                    }   
                    longitud--;
                }
            }

            /**
             * @param indice
             * @return eliminar
             */
            void  eliminar(int indice){

                if (estaVacio()) cout<< "Lista vacia. No existe nada que borrar"<<endl;
                else{

                    if(indiceOFL(indice)) cout <<"La lista no posee tantos elementos, o es de longitud negativa" <<endl;
                    else{
                        if(indice == 0){
                            //cout<<"Elimine inicio"<<endl;
                            eliminarInicio();

                        }else{   

                            NodoDC<T> *iterador = primero;

                            while(indice != 0){
                                iterador = iterador->getSiguiente();
                                indice--;
                            } 

                            if(iterador->getSiguiente() ==  primero){
                                //cout<<"Elimine final"<<endl;
                                eliminarFinal();
                            }else{
                                //cout<<"Elimine otro"<<endl;
                                NodoDC<T> *previo;
                                NodoDC<T> *siguiente;

                                previo = iterador->getAnterior();
                                siguiente = iterador->getSiguiente();

                                previo->setSiguiente(siguiente);
                                siguiente->setAnterior(previo);

                                free(iterador);
                                longitud--;
                            }   
                        }
                    }
                }
            }

            /**
             * @return imprimirInicio
             */
            void imprimirInicio(){

                if (estaVacio()){ 
                    cout<< "Lista vacia. No existe nada imprimir"<<endl;
                    return;
                }else{

                    NodoDC<T> *nimpreso;
                    nimpreso = primero;

                    cout << "\n... <- ";
                    while( nimpreso != ultimo){

                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getSiguiente();
                        cout<< " <-> ";
                       
                    }
                    cout << ultimo->getValor() << "  -> ..." <<endl;
                }
            }


            /**
             * @return imprimirFinal
             */
            void imprimirFinal(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada imprimir"<<endl;
                else{
                    
                        NodoDC<T> *nimpreso;
                        nimpreso = ultimo;

                        cout << "\n... <- ";
                        while( nimpreso != primero){

                            cout<< nimpreso -> getValor();
                            nimpreso = nimpreso->getAnterior();
                            cout<< " <-> ";
                        
                        }
                        cout << primero->getValor() << "  -> ..." <<endl;
                }
            }


            /**
             * @return imprimirObjetoInicio
             */
            void imprimirObjetoInicio(){
                if (estaVacio()){ 
                    cout<< "Lista vacia. No existe nada imprimir"<<endl;
                    return;
                }else{

                    NodoDC<T> *nimpreso;
                    nimpreso = primero;

                    while( nimpreso != ultimo){

                        cout<< nimpreso -> toString() <<endl;
                        nimpreso = nimpreso->getSiguiente();
                        
                       
                    }
                    cout << ultimo->toString()<<endl;
                }
            }


            /**
             * @return imprimirObjetoFinal
             */
            void imprimirObjetoFinal(){

                if (estaVacio()) cout<< "Lista vacia. No existe nada imprimir"<<endl;
                else{
                    
                        NodoDC<T> *nimpreso;
                        nimpreso = ultimo;

                        while( nimpreso != primero){

                            cout<< nimpreso -> toString()<<endl;
                            nimpreso = nimpreso->getAnterior();
                        
                        }
                        cout << primero->toString() <<endl;
                }
            }

            /**
             * @param indice
             * @return obtenerValorIndice
             */
            T obtenerValorIndice(int indice){
                if (estaVacio()){
                cout<< "Lista vacia. No existe nada que buscar"<<endl;
                return -1;
                }else{
                    
                    if(indice == 0){
                        return primero->getValor();
                    }else if(indice == longitud-1){
                        return ultimo->getValor();
                    }else{
                        NodoDC<T> *iterador = primero;

                        while(indice != 0){
                            iterador = iterador->getSiguiente();
                            indice--;
                        }

                        return iterador->getValor();
                    } 
                    return -1;  
                }
            }


            /**
             * @param indice
             * @param v
             * @return setValorIndice
             */
            void setValorIndice(int indice, T v){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que buscar"<<endl;
                else{
                    
                    if(indice == 0){
                        primero->setValor(v);
                    }else if(indice == longitud-1){
                        ultimo->setValor(v);
                    }else{
                        NodoDC<T> *iterador = primero;

                        while(indice != 0){
                            iterador = iterador->getSiguiente();
                            indice--;
                        }

                        iterador->setValor(v);
                    } 
                }
            }

            /**
             * @param indice
             * @param v
             * @return setValorIndice
             */
            int buscar(T buscado){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que buscar"<<endl;
                else{
                    NodoDC<T> *iterador = primero;
                    int indice = 0;
                    while( iterador != ultimo){
                        if(iterador->getValor() == buscado) return indice;
                        if(iterador->getSiguiente()->getValor() == buscado) return indice+1;
                        iterador = iterador->getSiguiente();
                        indice++;   
                    }
                }
                return -1;
            }

            /**
             * @param indice
             * @param v
             * @return setValorIndice
             */
            void imprimirBuscar(T buscado){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que buscar"<<endl;
                else{

                    if(buscar(buscado) == -1){
                        cout<< "No se encontro su instancia en la lista"<<endl;
                    }else{
                        cout<< "La primera instancia de valor se encuentra en el indice "<< buscar(buscado)<<endl;
                    }    
                }
            }

         

            /**
             * @return revertir
             */
            void revertir(){
                if (estaVacio()) cout<< "Lista vacia. No existe nada que revertir"<<endl;
                else{

                    ListaDobleC<T> *revertida = new ListaDobleC<T>();
                    NodoDC<T> *iterador = ultimo;

                    while(iterador != primero){
                        revertida->insertarFinal(iterador->getValor());
                        iterador = iterador->getAnterior();
                    }

                    revertida->insertarFinal(primero->getValor());
                    this->primero = revertida->primero;
                    this->ultimo = revertida->ultimo;
                    free(revertida);
                }
            }

            /**
             * @return imprimir
             */
            void imprimir(){
                if (estaVacio()){ 
                    cout<< "Lista vacia. No existe nada imprimir"<<endl;
                    return;
                }else{
                    NodoDC<T> *nimpreso;
                    nimpreso = primero;

                    while( nimpreso != ultimo){

                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getSiguiente();
                    }
                    cout << ultimo->getValor();
                }
            }

            /**
             * @return obtenerArray
             */

            T* obtenerArray(){

                T* array = new T[longitud];
                NodoDC<T> *actual = primero;

                int indice=0;
                while (actual != ultimo){
                    array[indice++] = actual -> getValor();
                    actual = actual ->getSiguiente();

                    if(actual->getSiguiente() == ultimo){
                        array[indice+1] = actual->getSiguiente() -> getValor();
                    }
                }

                return array;
            }


            
            /**
            * @return ordenar
            */

            void ordenar(){
                ListaDobleC<T> *ordenada = new ListaDobleC<T>(); 

                T* array = obtenerArray();

                for (int i = 0; i < longitud-1; i++) {
                    int min = i;

                    for (int j = i + 1; j < longitud; j++) {
                        if (array[j] < array[min]) {
                            min = j;
                        }
                    }

                    if (min != i) {
                        T temp = array[min];
                        array[min] = array[i];
                        array[i] = temp;
                    }
                }

                
                for(int u = 0; u < longitud; u++){
                   ordenada->insertarFinal(array[u]);
                }   
                
                this->primero = ordenada->primero;
                this->ultimo = ordenada->ultimo;
                free(ordenada);
                delete [] array;
            }


            /**
             * @return obtenerLongitud
             */
            int obtenerLongitud(){
                return this->longitud;
            }

            /**
             * @return NodoDC<obtenerPrimero>
             */
            NodoDC<T>* obtenerPrimero(){
                return this->primero;
            }


            /**
             * @return  NodoDC<obtenerUltimo>
             */
            NodoDC<T>* obtenerUltimo(){
                return this->ultimo;
            }

            /**
             * @param p
             * @return setPrimero
             */
            void setPrimero(NodoDC<T>* p){
                this->primero = p;
            }

            /**
             * @param u
             * @return setUltimo
             */
            void setUltimo(NodoDC<T>* u){
                this->ultimo = u;
            }
            
            /**
             * @return toString
             */
            string toString(){
                return "Cosillas";
            }
    };
