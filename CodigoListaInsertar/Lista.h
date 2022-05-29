#include "Nodo.h"
#include <exception>

class ListaEnlazada{

    private:
        Nodo *primero = nullptr;
        Nodo *ultimo = nullptr;
        bool estaVacio();
        Nodo* obtenerPrevio(Nodo*);
    public:

        ListaEnlazada();
        ~ListaEnlazada();
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

};