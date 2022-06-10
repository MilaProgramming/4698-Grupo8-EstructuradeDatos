/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#pragma once
#include "3Tienda.h"
#include "3Celular.cpp"
#include "1NodoDC.hpp"


    //Constructor y destructor

    Tienda::Tienda(){

    }

  /**
   * El destructor de la clase Tienda. Libera la memoria asignada al objeto y llama al destructor de la
   * clase Stock.
   */
    Tienda::~Tienda(){
        free(this);
        stock->~Stock();
    }

    //Funciones de excepciones, getter y setter

   /**
    * Comprueba si el stock está vacío.
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Tienda::estaVacio(){
        if(this->stock == nullptr){
            return true;
        }else if(this->stock->getCelulares()->estaVacio() || this->stock->getPersonas()->estaVacio()){
            return true;
        }
        else return false;
    }

   /**
    * `void Tienda::setStock(Stock * s)`
    * 
    * La función se llama `setStock` y es miembro de la clase `Tienda`. Toma un puntero a un objeto
    * `Stock` como argumento. no devuelve nada
    * 
    * Parameters
    * ----------
    * s : Stock
    * 	Objeto común
    */
    void Tienda::setStock( Stock * s){
        this->stock = s;
        establecerCorreos();
    }

    /**
     * `Stock* Tienda::getStock(){`
     * 
     * `devolver esto->stock;`
     * 
     * `}`
     * 
     * La función devuelve un puntero a un objeto Stock
     * 
     * Returns
     * -------
     * 	El stock de la tienda.
     */
    Stock*  Tienda::getStock(){
        return this->stock;
    }

    //Recomendaciones de compra   

    //!debe estar ordenada
    /**
     * Devuelve una lista de teléfonos celulares que están por debajo del presupuesto de la persona.
     * 
     * Parameters
     * ----------
     * persona : Persona
     * 	es un puntero a un objeto persona
     * 
     * Returns
     * -------
     * 	Un puntero a aListDobleC<Mobile*>
     */
    ListaDobleC<Celular*>* Tienda::recomendarCelulares(Persona* persona){
       //cout<<persona->getPresupuesto() <<endl;
       return celularesPorPresupuestoMenor(persona->getPresupuesto());
    } //Recomendar automaticamente a la persona un celular por presupuesto

    //!debe estar ordenada
    /**
     * Toma un doble como parámetro y devuelve una lista de punteros a objetos de Celular
     * 
     * Parameters
     * ----------
     * p : double
     * 	es el presupuesto
     * 
     * Returns
     * -------
     * 	Una lista de punteros a objetos de Celular.
     */
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMenor(double p){

        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerPrimero();
        int cont = 0;

        if (p > (stock->getCelulares()->obtenerUltimo()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                //cout<<"Entre a la condicion" <<endl;
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

        //cout<<"Llegue al final"<<endl;
        return presupuesto;
    } //Devolver los celulares menores o iguales que el presupuesto

    //!debe estar ordenada
   /**
    * Toma como parámetro un doble y devuelve una lista de punteros a objetos de tipo Celular
    * 
    * Parameters
    * ----------
    * p : double
    * 	es el precio que el usuario quiere gastar
    * 
    * Returns
    * -------
    * 	Una lista de punteros a objetos de Celular.
    */
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMayor(double p){

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
        
        return presupuesto;
    } //Devolver celulares mayores o iguales que el presupuesto

    //Devuelven listas de objetos que cumplan con ciertos requisitos

    ListaDobleC<Persona*>* Tienda::personasPorPresupuestoIgual(double valor) {

        //cout<< "Entre a la funcion encontrar" <<endl;

		/* El código anterior está creando una lista de personas que tienen un presupuesto igual al valor
        pasado como parámetro. */
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
	
    /**
     * Toma una cadena y una lista de punteros a objetos de tipo Persona, y devuelve una lista de punteros
     * a objetos de tipo Persona
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	cuerda
     * apellido : string
     * 	cuerda
     * 
     * Returns
     * -------
     * 	Una lista de personas con el mismo nombre y apellido.
     */
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

    /**
     * Esta función se utiliza para encontrar una persona en la lista de personas, recibe el nombre,
     * apellido, presupuesto y id de la persona a encontrar, crea una nueva persona con los datos
     * recibidos y luego la compara con las personas en la lista, si encuentra una persona igual a la
     * creada, la agrega a una nueva lista y la devuelve
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	cuerda
     * apellido : string
     * 	cuerda
     * presupuesto : double
     * 	doble
     * cedula : int
     * 	En t
     * 
     * Returns
     * -------
     * 	Una lista de punteros a Personas.
     */
    ListaDobleC<Persona*>* Tienda::personasIgual(string nombre, string apellido, double presupuesto, int cedula){
         
        Persona *p = new Persona(nombre, apellido, presupuesto, cedula); 
        //cout<< "Entre a la funcion encontrar" <<endl;
		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;

			if ((*(it->getValor()) == *p)){
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

   /**
    * Devuelve una lista de personas con el mismo nombre, apellido y DNI.
    * 
    * Parameters
    * ----------
    * nombre : string
    * 	cuerda
    * apellido : string
    * 	cuerda
    * cedula : unsigned long
    * 	largo sin firmar
    * 
    * Returns
    * -------
    * 	Una lista de punteros a objetos Person.
    */
    ListaDobleC<Persona*>* Tienda::personasIgual(string nombre, string apellido, unsigned long cedula){
         
        //Persona *p = new Persona(nombre, apellido, cedula); 
        //cout<< "Entre a la funcion encontrar" <<endl;
		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;

			if (it->getValor()->getNombre() == nombre && it->getValor()->getApellido() == apellido && it->getValor()->getCedula() == cedula){
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


   /**
    * Devuelve una lista de punteros a objetos de tipo Celular que tienen un precio determinado
    * 
    * Parameters
    * ----------
    * pres : double
    * 	doble
    * 
    * Returns
    * -------
    * 	Una lista de punteros a objetos de Celular.
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

	/**
     * Devuelve una lista de punteros a objetos de tipo Celular que tienen la misma marca que el pasado
     * como parámetro
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	el nombre de la marca
     * 
     * Returns
     * -------
     * 	Una lista de punteros a objetos de Celular.
     */
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


    /**
     * Agrega un nuevo celular al stock de la tienda, si el celular ya existe, aumenta el stock del
     * celular existente
     * 
     * Parameters
     * ----------
     * nuevo : Celular
     * 	es un puntero a un objeto Celular
     */
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

    /**
     * Toma un puntero a un objeto Celular y lo agrega a una lista de objetos Celular
     * 
     * Parameters
     * ----------
     * nuevo : Celular
     * 	es un puntero a un objeto Celular
     */
    void  Tienda::agregarCelularTiendaSinString(Celular* nuevo){

        if(stock->compararCelulares(nuevo)){

            cout<< "\n \n \n";
            stock->agregarStockRepetido(nuevo, nuevo->getStock());

            //cout << "\n~~~ El celular que desea agregar ya existe. Se ha aumentado el stock ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getCelulares()->insertarFinal(nuevo);
            //cout << "\n~~~ El celular se ha agregado con exito ~~~\n" <<endl;
        }

    }

    /**
     * Es una función que borra un celular de una lista de celulares
     * 
     * Parameters
     * ----------
     * c : Celular
     * 	es un puntero a un objeto Celular
     */
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

    /**
     * Toma una cadena, una cadena, una cadena, un doble y un largo como parámetros y no devuelve nada.
     * 
     * Parameters
     * ----------
     * celular : string
     * 	nombre del celular
     * persona : string
     * 	nombre de la persona
     * apersona : string
     * 	apellido
     * presupuesto : double
     * 	la cantidad de dinero que tiene la persona
     * cedula : long
     * 	largo
     */
    void Tienda::comprarCelular(string celular, string persona, string apersona, double presupuesto, long cedula){

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, presupuesto, cedula);

        if(c != nullptr && p!= nullptr){
            //cout<< "Compro celu" <<endl;
            p -> comprarCelular(c);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ Probablemente no se tiene suficiente presupuesto ~~~\n" <<endl;
        }
    }

    /**
     * Toma una cadena, una cadena, una cadena, un doble, un int y un largo como parámetros y no
     * devuelve nada.
     * 
     * Parameters
     * ----------
     * celular : string
     * 	nombre del celular
     * persona : string
     * 	nombre de la persona
     * apersona : string
     * 	apellido
     * presupuesto : double
     * 	la cantidad de dinero que tiene la persona
     * cantidad : int
     * 	cantidad del producto a comprar
     * cedula : long
     * 	largo
     */
    void  Tienda::comprarCelular(string celular, string persona, string apersona, double presupuesto, int cantidad, long cedula){

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, presupuesto, cedula);

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c, cantidad);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }

    /**
     * Toma una cadena, una cadena, una cadena y un largo como parámetros, y no devuelve nada.
     * 
     * Parameters
     * ----------
     * celular : string
     * 	cuerda
     * persona : string
     * 	cuerda
     * apersona : string
     * 	cuerda
     * cedula : long
     * 	largo
     */
    void Tienda::comprarCelular(string celular, string persona, string apersona, long cedula){

        //cout<< "Entro a comprar celular unico" <<endl;

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, cedula);

        cout << p->getPresupuesto() <<endl;

        if(c != nullptr && p!= nullptr){
            //cout<< "Compro celu" <<endl;
            p -> comprarCelular(c);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ Probablemente no se tiene suficiente presupuesto ~~~\n" <<endl;
        }
    }

    /**
     * "Si la persona y el celular existen, la persona compra el celular, de lo contrario, imprime un
     * mensaje de error".
     * 
     * El problema es que la función no funciona como se esperaba.
     * 
     * Parameters
     * ----------
     * celular : string
     * 	nombre del celular
     * persona : string
     * 	nombre de la persona
     * apersona : string
     * 	apellido
     * cantidad : int
     * 	cantidad de teléfonos para comprar
     * cedula : long
     * 	largo
     */
    void  Tienda::comprarCelular(string celular, string persona, string apersona, int cantidad, long cedula){

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, cedula);

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c, cantidad);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }
   

    /**
     * Toma como parámetros un puntero a una persona y un puntero a un celular y un número entero y si
     * los punteros no son nulos llama a la función comprarCellPhone de la clase persona
     * 
     * Parameters
     * ----------
     * p : Persona
     * 	puntero a una persona
     * c : Celular
     * 	es un puntero a un objeto Celular
     * cant : int
     * 	es la cantidad del producto que el usuario quiere comprar
     */
    void Tienda::comprarCelular(Persona* p, Celular* c, int cant){

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c, cant);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }

    /**
     * Se supone que la función toma un puntero a una persona y un puntero a un teléfono celular y
     * luego llama a la función "comprarCelular" de la clase "Persona" que se supone que toma el
     * teléfono celular y lo agrega al inventario de la persona.
     * 
     * Parameters
     * ----------
     * p : Persona
     * 	puntero a una persona
     * c : Celular
     * 	es un puntero a un objeto Celular
     */
    void Tienda::comprarCelular(Persona* p, Celular* c){

        //cout<< p->getPresupuesto() <<endl;

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }

    
    /**
     * Crea un nuevo objeto Stock, y luego establece el atributo celular del nuevo objeto Stock al
     * resultado de la función celularesPorMarcaIgual.
     * 
     * La función celularesPorMarcaIgual devuelve un objeto Lista.
     * 
     * La función setCelulares toma como parámetro un objeto Lista.
     * 
     * El conjunto
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	nombre de la marca
     */
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

   /**
    * Crea un nuevo objeto Stock y luego verifica si la lista está vacía. Si es así, imprime un
    * mensaje. Si no es así, establece la lista del nuevo objeto Stock en la lista devuelta por la
    * función y luego imprime la lista.
    * 
    * Parameters
    * ----------
    * precio : double
    * 	doble
    */
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

    /**
     * Agrega una persona a la lista de personas en la tienda
     * 
     * Parameters
     * ----------
     * p : Persona
     * 	es un puntero a un objeto persona
     */
    void Tienda::agregarPersonaTienda(Persona* p){
        
        if(stock->compararPersona(p)){

            cout << "\n~~~ La persona que desea registrar ya se encuentra en la Lista ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getPersonas()->insertarFinal(p);
            establecerCorreos();
            stock->verPersonas();
            cout << "\n\n~~~ La persona ha agregado con exito ~~~\n" <<endl;
        }
    }

   /**
    * Toma un puntero a un objeto Persona y lo agrega al final de una lista enlazada
    * 
    * Parameters
    * ----------
    * p : Persona
    * 	es un puntero a un objeto Person
    */
    void Tienda::agregarPersonaSinString(Persona* p){
        
        if(stock->compararPersona(p)){

            //cout << "\n~~~ La persona que desea registrar ya se encuentra en la Lista ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getPersonas()->insertarFinal(p);
            establecerCorreos();
            //stock->verPersonas();
            //cout << "\n\n~~~ La persona ha agregado con exito ~~~\n" <<endl;
        }
    }

    /**
     * Elimina a una persona de la lista.
     * 
     * Parameters
     * ----------
     * p : Persona
     * 	es un puntero a un objeto persona
     */
    void Tienda::eliminarPersonaTienda(Persona* p){

        if(stock->eliminarPersona(p)){
            cout<<"\n";
            stock->verPersonas();

            cout<< "\n ~~ Persona eliminada con exito ~~\n";
        }else{
            cout<< "\n ~~ Ninguna persona corresponde a estos datos. ~~\n";
        }
    }

    /**
     * Toma una cadena y una cadena e imprime las personas que coinciden con el nombre y el apellido.
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	cuerda
     * apellido : string
     * 	cuerda
     */
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
    
    /**
     * Crea un nuevo objeto Stock, luego verifica si la lista está vacía, si lo está, imprime un
     * mensaje, si no, establece la lista de personas en la lista de personas que coinciden con los
     * criterios, luego imprime la lista de personas
     * 
     * Parameters
     * ----------
     * presupuesto : double
     * 	es el presupuesto que el usuario quiere buscar.
     */
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

    /**
     * Toma un nombre, apellido, presupuesto y número de cédula y devuelve una lista de teléfonos que
     * coinciden con el presupuesto y el número de cédula
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	nombre de la persona
     * apellido : string
     * 	apellido
     * presupuesto : double
     * 	la cantidad de dinero que el usuario tiene que gastar
     * cedula : int
     * 	En t
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
    bool Tienda::recomendarAutomatico(string nombre, string apellido, double presupuesto, int cedula){
        this->stock->ordenarPorPrecio();
        Stock *por = new Stock();

        por -> setPersonas(personasIgual(nombre, apellido, cedula));

        if(por->getPersonas()->obtenerPrimero() != nullptr){
            por -> setCelulares(recomendarCelulares(por->getPersonas()->obtenerPrimero()->getValor()));
            por -> verCelulares();
            return true;
        }else{
            cout<< "\n~~~ No se han encontrado coincidencias ~~~\n" <<endl;
            return false;
        }

        free(por);
    }

    /**
     * Toma un doble como parámetro y devuelve un bool
     * 
     * Parameters
     * ----------
     * presupuesto : double
     * 	doble
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
    bool Tienda::recomendarMenores(double presupuesto){
        this->stock->ordenarPorPrecio();

        Stock *por = new Stock();

        por -> setCelulares(celularesPorPresupuestoMenor(presupuesto));
        if(por->getCelulares()->obtenerPrimero() != nullptr){
            por -> verCelulares();
            return true;
        }else{
            cout<< "\n~~~ No se han encontrado coincidencias ~~~\n" <<endl;
            return false;
        }

        free(por);
    }

    /**
     * Toma un doble como parámetro, ordena las acciones por precio, crea un nuevo objeto de acciones,
     * configura los celulares de las nuevas acciones al resultado de la función
     * celularesPorPresupuestoMayor, y luego imprime los celulares de las nuevas acciones.
     * 
     * Parameters
     * ----------
     * presupuesto : double
     * 	doble
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
    bool Tienda::recomendarMayores(double presupuesto){
        this->stock->ordenarPorPrecio();

        Stock *por = new Stock();

        por -> setCelulares(celularesPorPresupuestoMayor(presupuesto));
        
        if(por->getCelulares()->obtenerPrimero() != nullptr){
            por -> verCelulares();
            return true;
        }else{
             cout<< "\n~~~ No se han encontrado coincidencias ~~~\n" <<endl;
             return true;
        }
        
        free(por);
    }

     /**
      * Toma una lista de personas y les asigna una dirección de correo electrónico
      */
     void Tienda::establecerCorreos(){

        //cout<< "Establezco correos"<<endl;
        NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
        string nombre;
        string apellido;
        int cont = 0;

        //cout<< stock->getPersonas()->obtenerLongitud() <<endl;

        while(cont < stock->getPersonas()->obtenerLongitud()){

            int cuenta = 0;

            nombre = it->getValor()->getNombre();
            apellido = it->getValor()->getApellido();

            ListaDobleC<Persona*>* repetidos = personasPorNombreIgual(nombre, apellido);
            NodoDC<Persona*> *itRepetidos = repetidos->obtenerPrimero();
            //cout<< itRepetidos->toString()<<endl;

            if(repetidos->obtenerLongitud() == 1){

                itRepetidos->getValor()->setCorreo(stock->generarCorreo(nombre, apellido));
                //cout<< stock->generarCorreo(nombre, apellido) << " correo a asignar"<<endl;
                //cout<< itRepetidos ->getValor()->getCorreo() << " correo asignado" <<endl;
                //cout<< "Unico nombre"<<endl;

            }else if(repetidos->estaVacio()){
                cout << "~~~ Ocurrio un percance ~~~" <<endl;
                cont = stock->getPersonas()->obtenerLongitud();
            }else{
                
                //cout<< "Varios"<<endl;
                if(repetidos->obtenerPrimero()->getValor()->tieneCorreo()){
                    //cout<< "NO he establecido correos"<<endl;
                int cant;
                while(cant < repetidos->obtenerLongitud()){
                    itRepetidos->getValor()->setCorreo(stock->generarCorreo(nombre, apellido, cuenta));
                    //cout<< itRepetidos ->getValor()->getCorreo() << " correo asignado" <<endl;
                    itRepetidos = itRepetidos ->getSiguiente();
                    cuenta++;
                    cant++;
                }

                }

            }

            cont++;
            it = it->getSiguiente();
        }

    }

   /**
    * Comprueba si la longitud de la cadena está entre 9 y 11
    * 
    * Parameters
    * ----------
    * c : unsigned long
    * 	el numero de cedula
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Tienda::cedulaCorrecta(unsigned long c){
        string ced = to_string(c);
        int t = ced.length();

        if(t < 9 || t > 11){
            return false;
        }
        
        return true;
    }

   /**
    * Comprueba si el stock es mayor que 0.
    * 
    * Parameters
    * ----------
    * s : int
    * 	Valores
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Tienda::stockCorrecto(int s){
        return (s > 0);
    }

   /**
    * Devuelve verdadero si el parámetro es mayor que el precio más bajo de un celular en la tienda.
    * 
    * Parameters
    * ----------
    * p : double
    * 	doble
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Tienda::presupuestoCorrecto(double p){
        return (p > stock->menorPrecioCelular());
    }

   /**
    * Se supone que la función lee un archivo y crea un nuevo objeto de la clase Celular o Persona,
    * dependiendo del archivo, y luego lo agrega al vector respectivo
    * 
    * Parameters
    * ----------
    * nombre : string
    * 	nombre del archivo
    */
    void Tienda::importarCelulares(string nombre){

        ifstream file(nombre);
    
        string marca;
        double precio;
        int stock;

        int cont = 1;
        int verf = 0;

        while(file >> marca >> precio >> stock){
            
            //cout<< "Entre al while" <<endl;
            //cout<< marca << " " << precio << " " << stock <<endl;

            if(stockCorrecto(stock)){
                Celular* c = new Celular(marca,precio,stock);
                //cout<< c->toString()<<endl;
                agregarCelularTiendaSinString(c);
                verf = 1;
            }else{
                cout<< "En la fila " << cont << " se tiene un stock vacio. No se agrega el objeto"<<endl;
            }

            cont++;
        }

        //cout<< verf;
        if(verf == 1){
            cout << "\n~~ Se leyo y se agrego a los celulares con exito ~~"<<endl;
        }else{
            cout<< "\n~~ No se encontro el archivo ~~\n";
        }
       
        file.close();
    }

    /**
     * Lee un archivo y agrega los datos a un vector de punteros a objetos de la clase Persona
     * 
     * Parameters
     * ----------
     * nombre : string
     * 	nombre del archivo
     */
    void Tienda::importarPersonas(string nombre){

        ifstream file(nombre);
    
        string nom;
        string apellido;
        double presupuesto;
        unsigned long cedula;

        int cont = 1;
        int verf = 0;
        
        while(file >> nom >> apellido >> presupuesto >> cedula){
            if(presupuestoCorrecto(presupuesto) && cedulaCorrecta(cedula)){
                Persona *p = new Persona(nom, apellido, presupuesto, cedula);
                agregarPersonaSinString(p);
                verf=1;
            }else{
                cout<< "En la fila " << cont << " se tiene un presupuesto o cedula invalida"<<endl;
            }
        }

        if(verf == 1){
            cout << "\n~~ Se leyo y se agrego a los celulares con exito ~~"<<endl;
        }else{
            cout<< "\n~~ No se encontro el archivo ~~\n";
        }

        file.close();
    }


    /**
     * Toma como parámetro una cadena y crea un archivo con el nombre de la cadena y luego escribe la
     * información de la lista de celulares en el archivo
     * 
     * Parameters
     * ----------
     * m : string
     * 	mes
     */
    void Tienda::exportarCelulares(string m){

        string nom = "Celulares" + m;
        ofstream file(nom, ios::app);
        
 
        NodoDC<Celular*> *it = this->getStock()->getCelulares()->obtenerPrimero();
        int cont = 0;
        
        if(!(this->getStock()->getCelulares()->estaVacio())){

            while(cont < this->getStock()->getCelulares()->obtenerLongitud()){

                file << it->getValor()->getMarca() << ' ' << it->getValor()->getPrecio() << ' ' << it->getValor()->getStock() <<endl;
                it = it ->getSiguiente();
                cont++;
            }

            cout<< "Creado con exito" <<endl;

        }else{
            cout<< "\n Lista vacia"<<endl;
        }    
  
        file.close();

    }

    /**
     * Toma una cadena como parámetro y crea un archivo con el nombre de la cadena y luego escribe la
     * información de las personas en la lista
     * 
     * Parameters
     * ----------
     * m : string
     * 	es el nombre del archivo
     */
    void Tienda::exportarPersonas(string m){

        string nom = "Personas" + m;
        ofstream file(nom, ios::app);
        
 
        NodoDC<Persona*> *it = this->getStock()->getPersonas()->obtenerPrimero();
        int cont = 0;
        
        if(!(this->getStock()->getPersonas()->estaVacio())){

            while(cont < this->getStock()->getPersonas()->obtenerLongitud()){

                file << it->getValor()->getNombre() << ' ' << it->getValor()->getApellido() << ' ' << it->getValor()->getPresupuesto() << ' ' << it->getValor()->getCedula()<<endl;
                it = it ->getSiguiente();
                cont++;
            }

            cout<< "Creado con exito" <<endl;

        }else{
            cout<< "\n Lista vacia"<<endl;
        }    
  
        file.close();
    }

   /**
    * Toma una cadena como parámetro, crea un archivo con el nombre de la cadena y luego itera a través
    * de una lista de personas y escribe la información de cada persona en el archivo.
    * 
    * Parameters
    * ----------
    * m : string
    * 	mes
    */
    void Tienda::exportarInforme(string m){
        string nom = "Informe" + m;
        ofstream file(nom, ios::app);

        int indice = 0;
        NodoDC<Persona*> *it = this->getStock()->getPersonas()->obtenerPrimero();

        if(!(this->getStock()->getPersonas()->estaVacio())){
            while(indice < this->getStock()->getPersonas()->obtenerLongitud()){

                file << (it->getValor())->getNombre() << ", de presupuesto actual " << (it->getValor())->getPresupuesto() << ", y de cedula " << to_string(it->getValor()->getCedula()) << " ha comprado " <<endl;
                
                if (it->getValor()->getComprados()->estaVacio()) file<< " ningun celular todavia"<<endl;
                else{
                    
                    NodoDC<Celular*> *nimpreso = it->getValor()->getComprados()->obtenerPrimero();
                    int cont = 0;

                    while(cont < it->getValor()->getComprados()->obtenerLongitud()){

                        file << "Marca = " <<  nimpreso->getValor()->getMarca() + "\nPrecio = " + to_string(nimpreso->getValor()->getPrecio()) << " con ";


                        file<< it->getValor()->getCantidad()[cont] << " items de este tipo\n" <<endl;

                        nimpreso = nimpreso->getSiguiente();
                        cont++;
                    }

                }

                it = it->getSiguiente();
                indice++;
            }

                cout<< "Creado con exito" <<endl;
        }else{
        cout<< "\n Lista vacia"<<endl;
        } 
    }