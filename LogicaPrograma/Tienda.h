#pragma once
#include "ListaDC.hpp"
#include "Celular.cpp"
#include "Persona.cpp"
#include "Stock.cpp"

class Tienda{

    private: 
        Stock *stock = new Stock();
 
    public:    

        Tienda();
        ~Tienda();

        void setStock( Stock *);
        Stock* getStock();
        ListaDobleC<Celular*>* recomendarCelulares(Persona*); //Recomendar automaticamente a la persona un celular por presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMenor(double); //Devolver los celulares menores o iguales que el presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMayor(double); //Devolver celulares mayores o iguales que el presupuesto
};