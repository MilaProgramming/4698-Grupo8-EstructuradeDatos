//!Plantilla de una lista Simple. Incluye nodo.h

#include "Nodo.hpp"
#include <iostream>
using namespace std;

template <typename T>
    class ListaEnlazada{

        private:
            Nodo<T> *primero = nullptr;
            Nodo<T> *ultimo = nullptr;
            int longitud;
            Nodo<T>* obtenerPrevio(Nodo<T>*);
        public:

        ListaEnlazada(){ //Constructor
            longitud = 0;
        } 
        
        ~ListaEnlazada(){} // Destructor
        
        bool estaVacio(){
            return this -> primero == nullptr;
        }

        //!1
        void agregarFinal(T nuevo){
            Nodo<T> *n = new Nodo<T>(nuevo);

            if(estaVacio())
                primero = ultimo = n;
            else{
                ultimo -> setNodo(n);
                ultimo = n;
            }
            longitud++;
        }

        //!2
        void agregarInicio(T nuevo){

            Nodo<T> *n = new Nodo<T>(nuevo);

            if(estaVacio())
                primero = ultimo = n;
            else{
                n -> setNodo(primero);
                primero = n;
            }

            longitud++;
        }

        //!3
        void eliminarCabeza(){
            if(estaVacio()){ //Caso lista vacia
                cout<<("Lista vacia")<<endl;

            }else if (primero == ultimo) { //Caso unico elemento
                primero = ultimo = nullptr;

            }else{ //Caso estandar
                Nodo<T> *segundo = primero ->getNodo();
            
                primero = nullptr; //Elimino referencia
                primero = segundo;
            }

            longitud--;
        }

        //!4 
        void eliminarCola(){

            if(estaVacio()){ //Caso lista vacia
                cout<<("Lista vacia")<<endl;
            }else if (primero == ultimo) { //Caso unico elemento
                primero = ultimo = nullptr;
            }else{
                Nodo<T> *previo = obtenerPrevio(ultimo); 
                ultimo = previo;
                ultimo -> setNodo(nullptr);   
            }

            longitud--;
        }

        //!5 
        int buscarPrimerNodo(){
            if (estaVacio()){
            cout << "Su lista esta vacia" <<endl;
                return 0;
            }else{
                return primero -> getValor();
            }
        }

        //!6
        void imprimirCabeza(){
            Nodo<T> *nimpreso;
            nimpreso = primero;

            while( nimpreso != nullptr){
                cout<< nimpreso -> getValor() << " -> ";
                nimpreso = nimpreso->getNodo();
             }
            cout << " NULL";
        }

        //!7 
        void imprimirCola(){
            Nodo<T> *nimpreso;
            nimpreso = ultimo;

            cout << " NULL ";
            cout << " <- " << ultimo -> getValor();

            while(obtenerPrevio(nimpreso) != nullptr){
                nimpreso = obtenerPrevio(nimpreso);
                cout << " <- " << nimpreso ->getValor();
            }
        }

        //?Funciones extra

        int buscarIndice(T buscado){
            if(estaVacio()){
                return -1;
            }else{
                int indice = 0; 
                Nodo<T> *actual = primero;

                while(actual != nullptr){
                    if(actual->getValor() == buscado) return indice;
                        actual = actual->getNodo();
                        indice++;
                }
            }
            return -1;
        }

        bool contiene(T contenido){
            return buscarIndice(contenido) != -1;
        }

        int longitudLista(){
            return this-> longitud;
        }

        T* convertiraArray(){
            T* array = new T[longitud];
            Nodo<T> *actual = primero;
            int indice=0;
            while (actual != nullptr){
                array[indice++] = actual -> getValor();
                actual = actual ->getNodo();
            }

            return array;
        }

        void revertir(){
            if (estaVacio()) return;

            Nodo<T> *previo = primero;
            Nodo<T> *actual = primero -> getNodo();
        
            while(actual != nullptr){
                Nodo<T> *siguiente  = actual ->getNodo();
                actual -> setNodo(previo);
                previo = actual;
                actual = siguiente; 
            }

            ultimo = primero;
            ultimo -> setNodo(nullptr);
            primero = previo;
            
        }

        int obtenerValorIndiceRevertido(int k){

            if (k > longitud) return -1;
                
                Nodo<T> *a = primero;
                Nodo<T> *b = primero;

                for(int i = 0; i < k-1; i++){
                    b = b ->getNodo();
                }    

                while (b ->getNodo() != nullptr){
                    a = a ->getNodo();
                    b = b ->getNodo();
                } 

                return a -> getValor();
        }

    };