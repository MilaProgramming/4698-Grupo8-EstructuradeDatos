#pragma once
#include "ListaDC.hpp"
#include "Celular.cpp"
#include "Persona.cpp"
#include "Stock.h"

    Stock::Stock(){
    }

    Stock::~Stock(){
        free(this);
    }

    void  Stock::setCelulares(ListaDobleC<Celular>* l){
        this->lista = l;
    }

    void Stock::verCelulares(){

        int indice = 0;
        NodoDC<Celular> *it = lista->obtenerPrimero();

        while(indice < lista->obtenerLongitud()){
            if((it->getValor()).getStock() == 0){
                lista->eliminar(indice);
            }

            indice++;
            it = it->getSiguiente();    
        }

        lista->imprimirInicio();
    }//Celulares disponibles

    void Stock::verStock(){

    }
     // ver que celulares estan a la venta y su cantidad
    void Stock::verStock(Celular){

    } 
    //Ver cuantos celulares hay de la isntancia
    void Stock::agregarAlStock(Celular){

    }
     //Agregar un celular a la venta
    void Stock::informeCompraCelulares(){

    } //Ver usuario y la compra de celulares que ha hecho