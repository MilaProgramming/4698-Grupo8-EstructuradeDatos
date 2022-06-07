#pragma once
#include "ListaDC.hpp"
#include "Celular.h"
#include "Persona.cpp"

class Stock{

    private:
        ListaDobleC<Celular> *lista = new ListaDobleC<Celular>();  
    public:

        Stock();
        Celular* recomendarCelular(Persona*);
        void disminuirStock(string);


};