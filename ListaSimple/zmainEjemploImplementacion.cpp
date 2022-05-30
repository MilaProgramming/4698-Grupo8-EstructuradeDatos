//!Ejemplo de implementacion del template de la lista
//?Funciones de la clase Lista
/*
 ListaEnlazada();
        ~ListaEnlazada();

        bool estaVacio();

        //!1
        void agregarFinal(int);
        //!2
        void agregarInicio(int);
        //!3
        void eliminarCabeza();
        //!4 
        void eliminarCola();
        //!5 
        int buscarPrimerNodo();
        //!6
        void imprimirCabeza();
        //!7 
        void imprimirCola();

        //?Funciones extra
        
        int buscarIndice(int);
        bool contiene(int);
        int longitudLista();
        int* convertiraArray();
        void revertir();
        int obtenerValorIndiceRevertido(int);
*/

#include "Lista.hpp"
#include <cstdio>
using namespace std;

int main(){

    ListaEnlazada<int> *enteros = new ListaEnlazada<int>();

    enteros->agregarFinal(5);
    enteros->agregarFinal(10);
    enteros->agregarFinal(15);
    enteros->agregarFinal(20);
    cout << "\n";
    enteros->imprimirCabeza();

    ListaEnlazada<float> *reales = new ListaEnlazada<float>();

    reales->agregarFinal(1.5);
    reales->agregarFinal(2.6);
    reales->agregarFinal(3.7);
    cout << "\n";
    reales->imprimirCabeza();

    ListaEnlazada<char> *caracteres = new ListaEnlazada<char>();

    caracteres->agregarFinal('a');
    caracteres->agregarFinal('b');
    caracteres->agregarFinal('c');
    caracteres->agregarFinal('d');
    cout << "\n";
    caracteres->imprimirCabeza();

    enteros->~ListaEnlazada();
    reales->~ListaEnlazada();
    caracteres->~ListaEnlazada();
    
    return 0;
}