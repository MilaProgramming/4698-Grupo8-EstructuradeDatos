#pragma once
#include "ListaDC.hpp"
#include "Celular.h"
#include "Persona.cpp"

class Stock{

    private:
        ListaDobleC<Celular> *lista = new ListaDobleC<Celular>();  
    public:

        Stock();
        ~Stock();

        void verCelulares();
        void verStock();
        void verStock(Celular);
        void agregarAlStock(Celular);


};