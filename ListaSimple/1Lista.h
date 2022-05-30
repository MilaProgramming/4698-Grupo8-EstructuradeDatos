#include "1Nodo.h"
#include <exception>
#include "0Buscar.h"
#include "0Agregar.h"
#include "0Eliminar.h"
#include "0Imprimir.h"

class ListaEnlazada: public Buscar, public Agregar, public Eliminar, public Imprimir{

    private:
        Nodo *primero = nullptr;
        Nodo *ultimo = nullptr;
        int longitud;
        Nodo* obtenerPrevio(Nodo*);
    public:

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

};