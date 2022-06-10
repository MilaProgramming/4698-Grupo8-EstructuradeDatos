/*******************************************
 * ESPE
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
***************************************************************88/
   
/* Creating a class called ListaDobleC, which is a template class. */
#pragma once

/* Una clase de plantilla. */
#include <iostream>
#include "1NodoDC.hpp"
#include "2IInsertar.hpp"
#include "2IEliminar.hpp"
#include "2IBuscar.hpp"
#include "2ItoString.hpp"

using namespace std;

template <typename T>
    class ListaDobleC: public Insertar<T>, public Eliminar<T>, public Buscar<T>, public ToString{

     
       /**
        * `bool indiceOFL(int indice){ return indice >= longitud || índice < 0; }`
        * 
        * La función devuelve verdadero si el índice está fuera de los límites
        * 
        * Parameters
        * ----------
        * indice : int
        * 	índice
        * 
        * Returns
        * -------
        * 	un valor booleano.
        */
        private:
            NodoDC<T> *primero = nullptr;
            NodoDC<T> *ultimo = nullptr;
            int longitud;

            bool indiceOFL(int indice){
                return indice >= longitud  || indice < 0;
            }

        public:

            
           /**
            * Comprueba si la lista está vacía.
            * 
            * Returns
            * -------
            * 	un valor booleano.
            */
            bool estaVacio(){
                return primero == nullptr;
            }

           
           /**
            * Un constructor para la clase ListaDobleC.
            */
            ListaDobleC(){
                longitud = 0;
            }

           
          /**
           * Un destructor. Libera la memoria asignada para el primer y último nodo.
           */
            ~ListaDobleC(){
                free(primero);
                free(ultimo);
            }

           
           /**
            * Crea un nuevo nodo y luego conecta el nuevo nodo a los nodos existentes
            * 
            * Parameters
            * ----------
            * v : T
            * 	valor
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
            * Crea un nuevo nodo y luego conecta el nuevo nodo al último nodo de la lista.
            * 
            * Parameters
            * ----------
            * v : T
            * 	es el valor que se insertará en la lista
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
             * Inserta un nuevo nodo en la lista, en la posición especificada por el índice
             * 
             * Parameters
             * ----------
             * v : T
             * 	El valor a insertar
             * indice : int
             * 	índice de la lista
             * 
             * Returns
             * -------
             * 	un puntero al primer nodo de la lista.
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
           * Si la lista está vacía, cree un nuevo nodo con el valor v y configúrelo como el primer y
           * último nodo de la lista
           * 
           * Parameters
           * ----------
           * v : T
           * 	valor
           */
            
            void insertar(T v){
                if(longitud == 0){
                    NodoDC<T> *nuevo = new NodoDC<T>(v);
                    primero = ultimo = nuevo;
                    longitud++;
                }else cout<<"Cuidado. Su lista ya posee nodos" <<endl;
            }

           
           /**
            * Si la lista está vacía, imprime un mensaje que dice que no hay nada que eliminar. Si la
            * lista no está vacía, elimina el primer nodo y establece el segundo nodo como el primer
            * nodo
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
             * Elimina el último nodo de la lista.
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
             * Elimina un nodo de la lista, dado un índice
             * 
             * Parameters
             * ----------
             * indice : int
             * 	el índice del elemento a eliminar
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
            * Imprime la lista desde el primer nodo hasta el último nodo
            * 
            * Returns
            * -------
            * 	el valor del nodo.
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
            * Imprime la lista desde el último nodo hasta el primer nodo
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
             * Imprime la lista desde el primer nodo hasta el último nodo
             * 
             * Returns
             * -------
             * 	El método devuelve la representación de cadena del objeto.
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
            * Imprime el último elemento de la lista, luego imprime el elemento anterior al último
            * elemento, luego imprime el elemento anterior al elemento anterior al último elemento, y
            * así sucesivamente hasta que imprime el primer elemento
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
             * Devuelve el valor del nodo en el índice dado
             * 
             * Parameters
             * ----------
             * indice : int
             * 	el índice del elemento que desea obtener
             * 
             * Returns
             * -------
             * 	El valor del nodo en el índice dado.
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
             * Establece el valor del nodo en el índice dado al valor dado
             * 
             * Parameters
             * ----------
             * indice : int
             * 	el índice del nodo que desea cambiar
             * v : T
             * 	El valor a configurar
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
            * Devuelve el índice de la primera aparición del valor en la lista, o -1 si el valor no
            * está en la lista
            * 
            * Parameters
            * ----------
            * buscado : T
            * 	El valor a buscar
            * 
            * Returns
            * -------
            * 	El índice del elemento que se encontró.
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
             * Imprime el índice de la primera instancia del valor que estás buscando.
             * 
             * Parameters
             * ----------
             * buscado : T
             * 	El valor a buscar
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
             * Crea una nueva lista, itera a través de la lista original e inserta los valores en la
             * nueva lista en orden inverso, luego elimina la lista original y la reemplaza con la
             * nueva
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
             * Imprime la lista, pero no imprime el último elemento.
             * 
             * Returns
             * -------
             * 	el valor del nodo.
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
             * Crea una nueva matriz de tipo T, luego crea un nuevo nodo de tipo T, luego crea un nuevo
             * int, luego crea un ciclo while, luego crea una nueva instrucción if, luego devuelve la
             * matriz
             * 
             * Returns
             * -------
             * 	Una matriz de tipo T.
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
             * Crea una nueva lista, la llena con los elementos de la lista original, ordena la nueva
             * lista y luego reemplaza la lista original con la nueva
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
           * Devuelve la longitud de la matriz.
           * 
           * Returns
           * -------
           * 	La longitud de la matriz.
           */
            int obtenerLongitud(){
                return this->longitud;
            }

           /**
            * Devuelve el primer nodo de la lista.
            * 
            * Returns
            * -------
            * 	El primer nodo de la lista.
            */
            NodoDC<T>* obtenerPrimero(){
                return this->primero;
            }

           /**
            * Devuelve el último nodo de la lista.
            * 
            * Returns
            * -------
            * 	El último nodo de la lista.
            */
            NodoDC<T>* obtenerUltimo(){
                return this->ultimo;
            }

           /**
            * *|CURSOR_MARCADOR|*
            * 
            * Parameters
            * ----------
            * p : NodoDC<T>
            * 	es el puntero al primer nodo de la lista.
            */
            void setPrimero(NodoDC<T>* p){
                this->primero = p;
            }

          /**
           * `void setUltimo(NodoDC<T>* u){this->ultimo = u;}`
           * 
           * La función toma un puntero a un objeto NodoDC como argumento y establece el último puntero
           * para que apunte al objeto.
           * 
           * Parameters
           * ----------
           * u : NodoDC<T>
           * 	NodoDC<T>*
           */
            void setUltimo(NodoDC<T>* u){
                this->ultimo = u;
            }
            
            /**
             * Devuelve una cadena
             * 
             * Returns
             * -------
             * 	Se devuelve el método toString().
             */
            string toString(){
                return "Cosillas";
            }
    };