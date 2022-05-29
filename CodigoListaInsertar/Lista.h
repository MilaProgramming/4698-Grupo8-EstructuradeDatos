#include "Nodo.h"

class ListaEnlazada{

    private:
        Nodo *primero = nullptr;
        Nodo *ultimo = nullptr;
        bool estaVacio();
    public:

        ListaEnlazada();
        ~ListaEnlazada();
        //1
        void agregarFinal(int);
        //2
        void agregarInicio(int);
        //3
        void imprimirCabeza();
};