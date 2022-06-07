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

        void setCelulares(ListaDobleC<Celular>*); //Agregar una lista de celulares

        void verCelulares(); //Celulares disponibles
        void verStock(); // ver que celulares estan a la venta y su cantidad
        void verStock(Celular); //Ver cuantos celulares hay de la isntancia
        void agregarAlStock(Celular); //Agregar un celular a la venta
        void informeCompraCelulares(); //Ver usuario y la compra de celulares que ha hecho

};