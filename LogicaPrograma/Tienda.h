#pragma once
#include "ListaDC.hpp"
#include "Celular.cpp"
#include "Persona.cpp"
#include "Stock.cpp"

class Tienda{

    private: 
        Stock *stock;
        ListaDobleC<Persona> *clientes = new ListaDobleC<Persona>();  
    public:    
        Celular* recomendarCelular(Persona*);
        ListaDobleC<Celular>* celularesPorPresupuesto(double);
};