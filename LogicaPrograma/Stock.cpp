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


    void Stock::setPersonas(ListaDobleC<Persona*>* p){
        this->personas = p;
    }

    void  Stock::setCelulares(ListaDobleC<Celular*>* l){
        this->lista = l;
    }

    ListaDobleC<Celular*>* Stock::getCelulares(){
        return this->lista;
    }
    
    void Stock::verCelulares(){

        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        while(indice < lista->obtenerLongitud()){
            if((it->getValor())->getStock() == 0){
                lista->eliminar(indice);
            }

            indice++;
            it = it->getSiguiente();    
        }

        lista->imprimirObjetoInicio();
    }//Celulares disponibles

    void Stock::verStock(){
        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();
        while(indice < lista->obtenerLongitud()){
            cout<< it->toString();
            cout<< " con un stock de " << (it->getValor())->getStock() <<endl;
            indice++;
            it = it->getSiguiente();    
        }

    }
    // ver que celulares estan a la venta y su cantidad

    void Stock::verStock(Celular* c){
        cout<< "Se tiene " << c->getStock() << " unidades de este ejemplar";
    } 
    //Ver cuantos celulares hay de la isntancia

    void Stock::agregarAlStock(Celular* c){
        lista->insertarFinal(c);
    }

    //Agregar un celular a la venta
    void Stock::informeCompraCelulares(){

        int indice = 0;
        NodoDC<Persona*> *it = personas->obtenerPrimero();

        
        while(indice < personas->obtenerLongitud()){

            cout << (it->getValor())->getNombre() << " ha comprado" <<endl;
            (it->getValor())->verComprados();
            it = it->getSiguiente();
            indice++;
        }

    } //Ver usuario y la compra de celulares que ha hecho


    void Stock::ordenarPorPrecio(){
        

        Celular** array = new Celular*[lista->obtenerLongitud()];
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        int indice=0;

        while (indice < lista->obtenerLongitud()){
            array[indice++] = it->getValor();
            it = it ->getSiguiente();
        }


        ListaDobleC<Celular*> *ordenada = new ListaDobleC<Celular*>(); 

        for (int i = 0; i < lista->obtenerLongitud()-1; i++) {
            int min = i;

            for (int j = i + 1; j < lista->obtenerLongitud(); j++) {
                if (array[j]->getPrecio() < array[min]->getPrecio()) {
                    min = j;
                }
            }

            if (min != i) {
                Celular* temp = array[min];
                array[min] = array[i];
                array[i] = temp;
            }
        }

        /*
        for(int y = 0; y < lista->obtenerLongitud(); y++){
            cout<< array[y]->getPrecio() << " ";
        }
        */

        for(int u = 0; u < lista->obtenerLongitud(); u++){
            ordenada->insertarFinal(array[u]);
            //ordenada->imprimirObjetoInicio();
        }   
        
        //cout<< ordenada->obtenerPrimero()->getValor()->getMarca() <<endl;
        //cout<< ordenada->obtenerUltimo()->getValor()->getMarca() <<endl;

        lista->setPrimero(ordenada->obtenerPrimero());
        lista->setUltimo(ordenada->obtenerUltimo());

        free(ordenada);
        delete [] array;

    }
