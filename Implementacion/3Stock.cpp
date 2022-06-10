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
#include "1ListaDC.hpp"
#include "3Celular.cpp"
#include "3Persona.cpp"
#include "3Stock.h"
#include <cstring>

   /**
    * Un constructor para la clase Stock.
    */
    Stock::Stock(){
    }

   /**
    * Libera la memoria del objeto.
    */
    Stock::~Stock(){
        free(this);
        lista->~ListaDobleC();
        personas->~ListaDobleC();
    }


   /**
    * Establece el valor de la variable personas al valor de la variable p.
    * 
    * Parameters
    * ----------
    * p : ListaDobleC<Persona*>
    * 	Un puntero a un objeto ListaDobleC.
    */
    void Stock::setPersonas(ListaDobleC<Persona*>* p){
        this->personas = p;
    }

   /**
    * *|CURSOR_MARCADOR|*
    * 
    * Parameters
    * ----------
    * l : ListaDobleC<Celular*>
    * 	ListDobleC<Celular*>*
    */
    void  Stock::setCelulares(ListaDobleC<Celular*>* l){
        this->lista = l;
    }

    /**
     * Devuelve la lista de teléfonos móviles.
     * 
     * Returns
     * -------
     * 	Un puntero al objeto aListDobleC<Cellular*>.
     */
    ListaDobleC<Celular*>* Stock::getCelulares(){
        return this->lista;
    }
    
    /**
     * Devuelve la lista de personas.
     * 
     * Returns
     * -------
     * 	Un puntero a ListDobleC<Persona*>
     */
    ListaDobleC<Persona*>* Stock::getPersonas(){
        return this->personas;
    }

    /**
     * Imprime la lista de celulares disponibles
     */
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

    /**
     * Imprime el stock de cada artículo de la lista
     */
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

   /**
    * Imprime la lista de personas en stock
    */
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

   /**
    * Imprime el stock de un determinado celular.
    * 
    * Parameters
    * ----------
    * c : Celular
    * 	es un puntero a un objeto Celular
    */
    void Stock::verStock(Celular* c){
        cout<< "Se tiene " << c->getStock() << " unidades de este ejemplar";
    } 
    //Ver cuantos celulares hay de la isntancia

   /**
    * Agrega un celular al stock.
    * 
    * Parameters
    * ----------
    * c : Celular
    * 	es un puntero a un objeto Celular
    */
    void Stock::agregarAlStock(Celular* c){
        lista->insertarFinal(c);
    }

    //Agregar un celular a la venta
    /**
     * Se supone que debe imprimir el nombre, el presupuesto actual y la cédula de cada persona en la
     * lista, y luego imprimir los teléfonos que compraron.
     */
    void Stock::informeCompraCelulares(){

        int indice = 0;
        NodoDC<Persona*> *it = personas->obtenerPrimero();

        
        while(indice < personas->obtenerLongitud()){

            cout << (it->getValor())->getNombre() << ", de presupuesto actual " << (it->getValor())->getPresupuesto() << ", y de cedula ";
            cout<< to_string(it->getValor()->getCedula()); 
            cout<< " ha comprado " <<endl;
            (it->getValor())->verComprados();
            it = it->getSiguiente();
            indice++;
        }

    } //Ver usuario y la compra de celulares que ha hecho


   /**
    * Toma una lista de objetos y los ordena por precio
    */
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

   /**
    * Devuelve el precio del celular más barato del stock
    * 
    * Returns
    * -------
    * 	El precio del primer elemento de la lista.
    */
    double Stock::menorPrecioCelular(){

        ordenarPorPrecio();
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        return it->getValor()->getPrecio();
    }

    /**
     * Compara un objeto Celular con los objetos en una lista de objetos Celular
     * 
     * Parameters
     * ----------
     * c : Celular
     * 	es un puntero a un objeto Celular
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
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

    /**
     * Compara una persona con la lista de personas en el stock
     * 
     * Parameters
     * ----------
     * c : Persona
     * 	es un puntero a un objeto persona
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
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
    
   /**
    * Comprueba si un determinado celular ya está en stock, y si lo está, no hace nada
    * 
    * Parameters
    * ----------
    * c : Celular
    * 	es un puntero a un objeto Celular
    */
    void Stock::agregarStockRepetido(Celular* c){

        int indice = 0;
        NodoDC<Celular*> *it = lista->obtenerPrimero();

        while(indice < lista->obtenerLongitud()){
            if (*(it -> getValor()) == *c){
                indice = lista->obtenerLongitud();
            }
            indice++;
            it = it->getSiguiente();
        }

    }

    /**
     * Comprueba si un objeto Celular ya está en la lista, y si lo está, aumenta el stock de ese objeto
     * 
     * Parameters
     * ----------
     * c : Celular
     * 	es un puntero a un objeto Celular
     * cantidad : int
     * 	En t
     */
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

    /**
     * Elimina un nodo de una lista doblemente enlazada
     * 
     * Parameters
     * ----------
     * c : Celular
     * 	es un puntero a un objeto Celular
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
    bool Stock::eliminarCelular(Celular* c){
        


        NodoDC<Celular*> *it = lista->obtenerPrimero();
        int cont = 0;
   
        while(cont < lista->obtenerLongitud()){
            

 
            if((*(it->getValor()) == *c)){

                this->lista->eliminar(cont);
       
                return true;
            }else{
                cont++;
                it = it->getSiguiente();
            }

        }

        return false;
    }

    /**
     * Elimina a una persona de la lista de personas.
     * 
     * Parameters
     * ----------
     * c : Persona
     * 	es el objeto a eliminar
     * 
     * Returns
     * -------
     * 	Un valor booleano.
     */
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

   /**
    * Devuelve un puntero a un objeto Celular, que es una clase que creé.
    * 
    * Parameters
    * ----------
    * nombre : string
    * 	es el nombre del teléfono
    * 
    * Returns
    * -------
    * 	Un puntero a un objeto Celular.
    */
    Celular* Stock::retornarCelularporNombre(string nombre){

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
		return nullptr;
    }

    
   /**
    * Esta función devuelve un puntero a un objeto persona que está en la lista de personas
    * 
    * Parameters
    * ----------
    * nombre : string
    * 	cuerda
    * apellido : string
    * 	cuerda
    * presupuesto : double
    * 	doble
    * cedula : unsigned long
    * 	largo sin firmar
    * 
    * Returns
    * -------
    * 	Un puntero a una persona.
    */
    Persona* Stock::retornarPersonaporNombre(string nombre, string apellido, double presupuesto, unsigned long cedula){
   
		Persona *p = new Persona(nombre, apellido, presupuesto, cedula);
        NodoDC<Persona*> *it = personas->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < personas-> obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;
			if ((*(it->getValor()) == *p))
                return it->getValor();
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //cout<< c->toString();
        //l->imprimirObjetoFinal();
		return nullptr;
    }

   /**
    * Devuelve un puntero a un objeto persona.
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
    * 	Un puntero a una persona.
    */
    Persona* Stock::retornarPersonaporNombre(string nombre, string apellido, unsigned long cedula){
   
		//Persona *p = new Persona(nombre, apellido, cedula);
        NodoDC<Persona*> *it = personas->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < personas-> obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;
			if (it->getValor()->getNombre() == nombre && it->getValor()->getApellido() == apellido && it->getValor()->getCedula() == cedula)
                return it->getValor();
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //cout<< c->toString();
        //l->imprimirObjetoFinal();
		return nullptr;
    }

   /**
    * Toma una cadena, la convierte en una matriz de caracteres y luego concatena el primer carácter de
    * la matriz de caracteres con otra cadena.
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
    * 	Una cuerda
    */
    string Stock::generarCorreo(string nombre, string apellido){

        int l = nombre.length();
        char *n = new char[l+1];

        strcpy(n, nombre.c_str());

        string correo = n[0] + apellido + "@tiendaCelus.com";

        return correo;
    }

   /**
    * Toma una cadena, la convierte en una matriz de caracteres y luego la vuelve a convertir en una
    * cadena.
    * 
    * Parameters
    * ----------
    * nombre : string
    * 	cuerda
    * apellido : string
    * 	apellido
    * lugar : int
    * 	es el número del empleado, si es el primero es 0, si es el segundo es 1, etc.
    * 
    * Returns
    * -------
    * 	Una cuerda
    */
    string Stock::generarCorreo(string nombre, string apellido, int lugar){

        int l = nombre.length();
        char *n = new char[l+1];

        strcpy(n, nombre.c_str());

        string correo;
        
        if(lugar == 0){
            correo = generarCorreo(nombre, apellido);
        }else{
            correo = n[0] + apellido + to_string(lugar) + "@tiendaCelus.com";
        }

        return correo;
    }


