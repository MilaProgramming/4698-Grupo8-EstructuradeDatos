#pragma once
#include "3Tienda.h"
#include "3Celular.cpp"
#include "1NodoDC.hpp"

    //Constructor y destructor
    Tienda::Tienda(){

    }

    Tienda::~Tienda(){
        free(this);
        stock->~Stock();
    }

    //Funciones de excepciones, getter y setter

    bool Tienda::estaVacio(){
        if(this->stock == nullptr){
            return true;
        }else if(this->stock->getCelulares()->estaVacio() || this->stock->getPersonas()->estaVacio()){
            return true;
        }
        else return false;
    }

    void Tienda::setStock( Stock * s){
        this->stock = s;
    }

    Stock*  Tienda::getStock(){
        return this->stock;
    }

    //Recomendaciones de compra   

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::recomendarCelulares(Persona* persona){
       //cout<<persona->getPresupuesto() <<endl;
       return celularesPorPresupuestoMenor(persona->getPresupuesto());
    } //Recomendar automaticamente a la persona un celular por presupuesto

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMenor(double p){

        this->stock->ordenarPorPrecio();
        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerPrimero();
        int cont = 0;

        if (p > (stock->getCelulares()->obtenerUltimo()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                cout<<"Entre a la condicion" <<endl;
        }

        while(cont < stock->getCelulares()->obtenerLongitud()){
            //cout<<"Entro al while grande"<<endl;
            //cout<< (it->getValor())->getPrecio() << " " << p <<endl;
            if((it->getValor())->getPrecio() > p){

               it = it->getAnterior(); 
               while(cont != 0){
                    //cout<<"Entro al while peque"<<endl;
                    //cout<< cont <<endl;
                    presupuesto->insertarFinal(it->getValor());
                    it = it->getAnterior();
                    cont --;
                }

               cont = stock->getCelulares()->obtenerLongitud();
            }else{
            it = it->getSiguiente();
            cont++;
            }
        }

        if(presupuesto->obtenerPrimero() == nullptr){
            cout << "No se encontro el criterio" <<endl;
        }

        //cout<<"Llegue al final"<<endl;
        return presupuesto;
    } //Devolver los celulares menores o iguales que el presupuesto

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMayor(double p){

        this->stock->ordenarPorPrecio();
        //this->getStock()->getCelulares()->imprimirObjetoInicio();
        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerUltimo();
        int cont = 0;

        if (p < (stock->getCelulares()->obtenerPrimero()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                //cout<<"Entre a la condicion" <<endl;
        }

        while(cont < stock->getCelulares()->obtenerLongitud()){
            //cout<< (it->getValor())->getPrecio() << " " << p <<endl;

            if((it->getValor())->getPrecio() < p){

               it = it->getSiguiente();
               while(cont != 0){ 
                   //cout<< cont <<endl;
                   presupuesto->insertarFinal(it->getValor());
                   it = it->getSiguiente();
                   cont --;
                }

               cont = stock->getCelulares()->obtenerLongitud();
            }

            it = it->getAnterior();
            cont++;
        }
        
        
        if(presupuesto == nullptr){
            cout << "No se encontro el criterio" <<endl;
        }

        return presupuesto;
    } //Devolver celulares mayores o iguales que el presupuesto

    //Devuelven listas de objetos que cumplan con ciertos requisitos

    ListaDobleC<Persona*>* Tienda::personasPorPresupuestoIgual(double valor) {

        //cout<< "Entre a la funcion encontrar" <<endl;

		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
        Celular *c = new Celular();
		int cont = 0;
		
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< "Entre al while" <<endl;
            //cout<< (c->iguales(it->getValor()->getPresupuesto(), valor, 0.01)) <<endl;
			if (c->iguales(it->getValor()->getPresupuesto(), valor, 0.01)){
				l->insertarFinal(it->getValor());
                //cout<<"Entro al if"<<endl;
            }   
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout<<"Salgo de la funcion"<<endl;
		return l;
	}
	
	ListaDobleC<Persona*>* Tienda::personasPorNombreIgual(string nombre, string apellido) {

        //cout<< "Entre a la funcion encontrar" <<endl;
		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;

			if (it->getValor()->getNombre() == nombre && it->getValor()->getApellido() == apellido){
				l->insertarFinal(it->getValor());
                //cout<< "Entre al if y agregue" <<endl;
            }
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
	}

    /*
    ListaDobleC<Persona*>* Tienda::personasPorApellidoIgual(string valor) {

		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;
			if (it->getValor()->getApellido() == valor)
				l->insertarFinal(it->getValor());
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
	}
    */

    ListaDobleC<Celular*>* Tienda::celularesPorPrecioIgual(double pres){

        //cout<< "stock->getCelulares()->obtenerLongitud()" <<endl;

        ListaDobleC<Celular*>* l = new ListaDobleC<Celular*>();
		NodoDC<Celular*> *it = stock->getCelulares()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getCelulares()->obtenerLongitud()) {
            //cout<< it->getValor()->getPrecio() <<endl;
			if (it->getValor()->getPrecio() == pres){
                //cout<< "Entro al if"<<endl;
				l->insertarFinal(it->getValor());
            }
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }

	ListaDobleC<Celular*>* Tienda::celularesPorMarcaIgual(string nombre){

        //cout<< stock->getCelulares()->obtenerLongitud()<<endl;
        ListaDobleC<Celular*>* l = new ListaDobleC<Celular*>();
		NodoDC<Celular*> *it = stock->getCelulares()->obtenerPrimero();
		int cont = 0;
		
        //cout << nombre <<endl;

		while (cont < stock->getCelulares()->obtenerLongitud()) {
            // /cout<< it->getValor()->getMarca() <<endl;

			if (it->getValor()->getMarca() == nombre)
				l->insertarFinal(it->getValor());
				
			it = it->getSiguiente();
			cont++;
		}

        /*
        if(l->obtenerPrimero() == nullptr){
            cout<< "No se encontro la instancia"<<endl;
        }
        */
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }


    void Tienda::agregarCelularTienda(Celular* nuevo){

        if(stock->compararCelulares(nuevo)){

            cout<< "\n \n \n";
            stock->agregarStockRepetido(nuevo, nuevo->getStock());
            stock->verCelulares();

            cout << "\n~~~ El celular que desea agregar ya existe. Se ha aumentado el stock ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getCelulares()->insertarFinal(nuevo);
            stock->verCelulares();
            cout << "\n~~~ El celular se ha agregado con exito ~~~\n" <<endl;
        }

        //cout<<stock->getCelulares()->obtenerLongitud()<<endl;

    }

    void Tienda::eliminarCelularTienda(Celular* c){

        if(stock->eliminarCelular(c)){
            cout<<"\n";
            stock->verCelulares();

            cout<< "\n ~~ Celular eliminado con exito ~~\n";
        }else{
            cout<< "\n ~~ Ningun celular corresponde a estos datos. ~~\n";
        }

        //cout<<stock->getCelulares()->obtenerLongitud()<<endl;
    }

    void Tienda::comprarCelular(string celular, string persona){

        Celular *c = stock->retornarCelularporNombre(celular);
        Persona *p = stock->retornarPersonaporNombre(persona);

        p -> comprarCelular(c);
    }
   
    
    void Tienda::buscarPorNombreCelular(string nombre){

        Stock *s = new Stock();
        if(celularesPorMarcaIgual(nombre)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            s->setCelulares(celularesPorMarcaIgual(nombre));
            s -> verStock();
            free(s);
        }

    }

    void Tienda::buscarPorPrecioCelular(double precio){

        Stock *a = new Stock();
        if(celularesPorPrecioIgual(precio)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            a -> setCelulares(celularesPorPrecioIgual(precio));
            a ->verStock();
            free(a);
        }
    }

    void Tienda::agregarPersonaTienda(Persona* p){
        
        if(stock->compararPersona(p)){

            cout << "\n~~~ La persona que desea registrar ya se encuentra en la Lista ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getPersonas()->insertarFinal(p);
            stock->verPersonas();
            cout << "\n\n~~~ La persona ha agregado con exito ~~~\n" <<endl;
        }
    }

    void Tienda::eliminarPersonaTienda(Persona* p){
        if(stock->eliminarPersona(p)){
            cout<<"\n";
            stock->verPersonas();

            cout<< "\n ~~ Persona eliminada con exito ~~\n";
        }else{
            cout<< "\n ~~ Ninguna persona corresponde a estos datos. ~~\n";
        }
    }

    void Tienda::buscarPorNombrePersona(string nombre, string apellido){
        Stock *a = new Stock();

        //cout<< "Entre a la funcion buscar" <<endl;
        if(personasPorNombreIgual(nombre, apellido)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            //cout<< "Holi" <<endl;
            a -> setPersonas(personasPorNombreIgual(nombre, apellido));
            //cout<< "Holi2" <<endl;
            //a -> getPersonas() ->imprimirObjetoFinal();
            a ->verPersonas();
            free(a);
        }
    }
    
    void Tienda::buscarPorPresupuestoPersona(double presupuesto){
        Stock *a = new Stock();
        //cout<< "Entre a la funcion buscar" <<endl;
        if(personasPorPresupuestoIgual(presupuesto)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            a -> setPersonas(personasPorPresupuestoIgual(presupuesto));
            a ->verPersonas();
            free(a);
        }
    }