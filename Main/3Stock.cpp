#pragma once
#include "1ListaDC.hpp"
#include "3Celular.cpp"
#include "3Persona.cpp"
#include "3Stock.h"

    Stock::Stock(){
    }

    Stock::~Stock(){
        free(this);
        lista->~ListaDobleC();
        personas->~ListaDobleC();
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
    
    ListaDobleC<Persona*>* Stock::getPersonas(){
        return this->personas;
    }

    void Stock::verCelulares(){

        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        cout<< "\n\nCelulares en venta\n" <<endl;
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
        int cont =1;
        NodoDC<Celular*> *it = lista->obtenerPrimero();
        while(indice < lista->obtenerLongitud()){
            cout<< "\n\n" << cont << ")" << endl;
            cout<< it->toString();
            cout<< "con un stock de " << (it->getValor())->getStock() <<endl;
            indice++;
            cont++;
            it = it->getSiguiente();    
        }

    }
    // ver que celulares estan a la venta y su cantidad

    void Stock::verPersonas(){
        int indice = 0;
        int cont =1;
        NodoDC<Persona*> *it = personas->obtenerPrimero();

        while(indice < personas->obtenerLongitud()){
            cout<< "\n\n" << cont << ")" << endl;
            cout<< it->toString();
            indice++;
            cont++;
            it = it->getSiguiente();    
        }
    }

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

            cout << (it->getValor())->getNombre() << ", de presupuesto actual " << (it->getValor())->getPresupuesto() << " ha comprado " <<endl;
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

        //free(ordenada);
        //delete [] array;

    }

    bool Stock::compararCelulares(Celular* c){

        //cout<<"Ingrese el metodo"<<endl;

        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();
        //cout<< lista->obtenerLongitud() <<endl;
        //cout << (*(it -> getValor()) == *c) <<endl;

        while(indice < lista->obtenerLongitud()){

            //cout<<"Entre al while"<<endl;
    
            //cout << (*(it -> getValor()) == *c) << " condicion"<<endl;
            //cout << it -> getValor() ->getMarca() <<endl;

            //cout<<"Voy a entrar al if"<<endl;
            //!if(**Celular == **Celular)
            if ( (*(it -> getValor()) == *c) ){
                //cout<<"Es verdadero"<<endl;
                return true;
            }

            indice++;
            //cout<< lista->obtenerLongitud() <<endl;
            //cout << it -> getValor() ->getMarca() <<endl;
            //cout<< c->getMarca() <<endl;

            it = it->getSiguiente();
        }

        //cout<<"sali sin mucha novedad"<<endl;
        return false;
    }

    bool Stock::compararPersona(Persona* c){

        int indice = 0;
        NodoDC<Persona*> *it = personas->obtenerPrimero();

        while(indice < lista->obtenerLongitud()){
            if ( (*(it -> getValor()) == *c) ){
                //cout<<"Es verdadero"<<endl;
                return true;
            }

            indice++;
            it = it->getSiguiente();
        }

        return false;
    }
    
    void Stock::agregarStockRepetido(Celular* c){

        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        while(indice < lista->obtenerLongitud()){
            if (*(it -> getValor()) == *c){
                it->getValor()->aumentarCantidad(1);
                indice = lista->obtenerLongitud();
            }
            indice++;
            it = it->getSiguiente();
        }

    }

    void Stock::agregarStockRepetido(Celular* c, int cantidad){

        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        while(indice < lista->obtenerLongitud()){

            if (*(it -> getValor()) == *c){
                //cout<< "Entro al if de stock repetido"<<endl;
                //cout<< it->getValor()->getMarca()<<endl;
                //cout<< it->getValor()->getStock()<<endl;
                it->getValor()->aumentarStock(cantidad);
                //cout<< it->getValor()->getCantidad()<<endl;
                indice = lista->obtenerLongitud();
            }
            indice++;
            it = it->getSiguiente();
        }
    }

    bool Stock::eliminarCelular(Celular* c){
        
        //cout <<"Funcion eleiminar" <<endl;
        //cout<< this->lista->obtenerLongitud() <<endl;
        //cout << c->toString();

        NodoDC<Celular*> *it = lista->obtenerPrimero();
        int cont = 0;
   
        while(cont < lista->obtenerLongitud()){
            
            //cout<< it->getValor()->getMarca() <<endl;
 
            if((*(it->getValor()) == *c)){
                //cout<<"Entre al if" <<endl;
                //cout<< cont <<endl;
                this->lista->eliminar(cont);
                //cout<< this->lista->obtenerLongitud() <<endl;
                //cout<<"Termine el if"<<endl;
                return true;
            }else{
                cont++;
                it = it->getSiguiente();
            }

        }

        //cout<< this->lista->obtenerLongitud() <<endl;
        //cout<<"Estoy afuera";
        //cout<< "Sali del while" <<endl;
        
        return false;
    }

    bool Stock::eliminarPersona(Persona* c){
        NodoDC<Persona*> *it = personas->obtenerPrimero();
        int cont = 0;

        while(cont < personas->obtenerLongitud()){
            
            if((*(it->getValor()) == *c)){
                this->personas->eliminar(cont);
                return true;
            }else{
                cont++;
                it = it->getSiguiente();
            }

        }

        return false;
    }

    Celular* Stock::retornarCelularporNombre(string nombre){

        Celular *c = new Celular();
		NodoDC<Celular*> *it = lista->obtenerPrimero();
		int cont = 0;
		
        //cout << "\n" << nombre <<endl;
        //cout << "\n" << lista-> obtenerLongitud() <<endl;
        
		while (cont < lista-> obtenerLongitud()) {
            //cout<< it->getValor()->getMarca() <<endl;

			if (it->getValor()->getMarca() == nombre){
                //cout<< "Entre el if"<<endl;
                //cout << c->toString();
                return it->getValor();
                //cout << c->toString();
            }
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
		return c;
    }

    
    Persona* Stock::retornarPersonaporNombre(string nombre, string apellido){
   
		NodoDC<Persona*> *it = personas->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < personas-> obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;
			if (it->getValor()->getNombre() == nombre && it->getValor()->getApellido() == apellido)
                return it->getValor();
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //cout<< c->toString();
        //l->imprimirObjetoFinal();
		return nullptr;
    }
    
