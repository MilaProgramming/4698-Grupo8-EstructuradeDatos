
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

#include "3Persona.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

   /**
    * La función toma una cadena, una cadena, un doble y un largo sin signo y establece los valores de
    * las variables de clase a los valores de los parámetros.
    * 
    * Parameters
    * ----------
    * n : string
    * 	nombre
    * m : string
    * 	apellido
    * p : double
    * 	presupuesto
    * c : unsigned long
    * 	cedula
    */
    Persona::Persona(string n, string m, double p, char* c){
        this->nombre = n;
        this ->apellido = m;
        this->presupuesto = p;
        this->cedula = c;
    }

    /**
     * La función `Persona::Persona(string n, string m, long c)` es un constructor de la clase `Persona`
     * 
     * Parameters
     * ----------
     * n : string
     * 	nombre
     * m : string
     * 	apellido
     * c : long
     * 	cedula
     */

    Persona::Persona(string n, string m, char* c){
        this->nombre = n;
        this ->apellido = m;
        this->cedula = c;
    }

    /**
     * El destructor para la clase Persona.
     */
    Persona::~Persona(){
        delete [] cantidad;
        free(this);
    }

    /**
     * Un constructor para la clase Persona.
     */
    Persona::Persona(){
    }

    /**
     * Una función que permite al usuario comprar un teléfono celular.
     * 
     * Parameters
     * ----------
     * celu : Celular
     * 	es un puntero a un objeto Celular
     */
    void Persona::comprarCelular(Celular* celu){

        //cout<< "entro a comprar celu" <<endl;
        //!verifico si he comprado el celu antes
        if(verificarCelular(celu)){
            //cout<< "1 if" <<endl;
            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                //cout<< "2 if" <<endl;
                //cout<< this->presupuesto - celu->getPrecio() <<endl;
                if(this->presupuesto - celu->getPrecio() > 0){
                    //cout<< "3 if" <<endl;
                    if(celu->disminuirStock()){
                       //cout<< "4 if" <<endl;
                        this->presupuesto -= celu->getPrecio();
                        //cout<< "\n" <<endl;
                        //cout<< this->presupuesto << "presupuesto luego de la compra" <<endl;
                        this->comprados->insertarFinal(celu);
                        cantidad[comprados->obtenerLongitud()-1] = 1;

                        //cout<< cantidad[comprados->obtenerLongitud()-1] <<endl;
                        cout<< "\n-- Compra realizada con exito --" <<endl;

                    }else{
                        //cout<< "5 if" <<endl;
                        celu->disminuirStock(); 
                    }

                }else{
                    //cout<< "6 if" <<endl;
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                } 

            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            } 

        }else{

            //!CASO CELULAR YA COMPRADO

            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                
                //cout<< "\n" <<endl;
                //cout<< this->presupuesto - celu->getPrecio() <<endl;

                if(this->presupuesto - celu->getPrecio() > 0){

                    //cout << "Entre al if de presupuesto "<<endl;
                    if(celu->disminuirStock()){

                        this->presupuesto -= celu->getPrecio();

                        //!recorro
                        NodoDC<Celular*> *it =comprados->obtenerUltimo();
                        int cont = 0;
                        int aux = 0;

                        while(cont < comprados->obtenerLongitud()){
                            if(*(it -> getValor()) == *celu){
                                aux = cont;
                                cont = comprados->obtenerLongitud();
                            }

                            it = it->getAnterior();
                            cont++;
                        }

                        cantidad[aux] += 1;

                        //cout<< "\n" <<endl;
                        //cout<< this->presupuesto << "presupuesto luego de la compra"<<endl;

                        cout<< "\n-- Compra realizada con exito --" <<endl;
                        //cout<< cantidad[aux] <<endl;
                    }else{
                        celu->disminuirStock();                
                    }    
                }else{
                cout<< "\n\nNo posee el suficiente dinero para comprar esto\n" <<endl;   
                }
            }else{
                cout<< "\n\nNo posee el suficiente dinero para comprar esto\n" <<endl;   
            }   
        }
    }
    
    /**
     * La funcion comra mas de un celular
     * 
     * Parameters
     * ----------
     * celu : Celular
     * 	es un puntero a un objeto Celular
     * cant : int
     * 	es la cantidad del producto que el usuario quiere comprar
     */
    void Persona::comprarCelular(Celular* celu, int cant){

      //!verifico si he comprado el celu antes
        if(verificarCelular(celu)){
            //cout<< "1 if" <<endl;
            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                //cout<< "2 if" <<endl;
                //cout<< this->presupuesto - celu->getPrecio() <<endl;
                if(this->presupuesto - ((celu->getPrecio())*cant) > 0){

                    if(celu->disminuirStock()){
                        //cout<< "4 if" <<endl;
                        this->presupuesto -= (celu->getPrecio())*cant;
                        //cout<< "\n" <<endl;
                             //cout<< this->presupuesto << "presupuesto luego de la compra"<<endl;
                        this->comprados->insertarFinal(celu);
                        cantidad[comprados->obtenerLongitud()-1] = cant;

                        //cout<< "\n" <<endl;
                        //cout<< cant << " cantidad"<<endl;
                       // cout<< cantidad[comprados->obtenerLongitud()-1] <<endl;
                        cout<< "\n-- Compra realizada con exito --" <<endl;

                    }else{
                        //cout<< "3 if" <<endl;
                        celu->disminuirStock(); 
                    }

                }else{
                    //cout<< "5 if" <<endl;
                    cout<< "\n\nNo posee el suficiente dinero para comprar esto\n" <<endl;   
                } 

            }else{
                cout<< "\n\nNo posee el suficiente dinero para comprar esto\n" <<endl;   
            } 

        }else{

            //!CASO CELULAR YA COMPRADO

            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                //cout<< "1 if" <<endl;
                //cout<< "\n" <<endl;
                //cout<< this->presupuesto - (celu->getPrecio())*cant <<endl;
                if(this->presupuesto - (celu->getPrecio())*cant > 0){

                    if(celu->disminuirStock()){

                        //cout<< "3 if" <<endl;
                        this->presupuesto -= (celu->getPrecio())*cant;
                        //cout<< "\n" <<endl;
                         //cout<< this->presupuesto << "presupuesto luego de la compra"<<endl;
                        //!recorro
                        NodoDC<Celular*> *it =comprados->obtenerUltimo();
                        int cont = 0;
                        int aux = 0;

                        while(cont < comprados->obtenerLongitud()){
                            if(*(it -> getValor()) == *celu){
                                aux = cont;
                                cont = comprados->obtenerLongitud();
                            }

                            it = it->getAnterior();
                            cont++;
                        }

                        //cout<< cant << " cantidad"<<endl;
                        //cout<< cantidad[aux] <<endl;
                        cantidad[aux] += cant;
                        
                    }else{
                        celu->disminuirStock();                
                    }    
                }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                }
            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            }   
        }

      
    }

    
  /**
   * Comprueba si un celular ya está en la lista de celulares comprados por el usuario
   * 
   * Parameters
   * ----------
   * celu : Celular
   * 	es un puntero a un objeto Celular
   * 
   * Returns
   * -------
   * 	Un valor booleano.
   */
    bool Persona::verificarCelular(Celular* celu){

        NodoDC<Celular*> *it =comprados->obtenerUltimo();
        int cont = 0;

        while(cont < comprados->obtenerLongitud()){ 
            if(*(it -> getValor()) == *celu){
                return false;
            }
            cont++;
            it = it->getAnterior();
        }

        return true;
    }

    /**
     * `bool Persona::disminuirPresupuesto()`
     * 
     * Returns
     * -------
     * 	un valor booleano.
     */
    bool Persona::disminuirPresupuesto(){
        if(this->presupuesto > 0){
            return true;
        }
        else return false;
    }

   /**
    * Devuelve el valor de la variable correo.
    * 
    * Returns
    * -------
    * 	el valor de la variable correo.
    */
    string Persona::getCorreo(){
        return this ->correo;
    }
    
   /**
    * Establece el valor de la variable correo.
    * 
    * Parameters
    * ----------
    * c : string
    * 	cuerda
    */
    void Persona::setCorreo(string c){
        this -> correo = c;
    }

   /**
    * Esta función devuelve el valor de la variable privada cedula
    * 
    * Returns
    * -------
    * 	El valor de la cédula del atributo.
    */
    char* Persona::getCedula(){
        return this->cedula;
    }

   /**
    * Esta función establece el valor de la variable privada cedula al valor del parámetro c
    * 
    * Parameters
    * ----------
    * c : unsigned long
    * 	La nueva cédula para el objeto.
    */
    void Persona::setCedula(char* c){
        this->cedula = c;
    }

   /**
    * Devuelve el valor de la variable privada cantidad.
    * 
    * Returns
    * -------
    * 	El puntero a la variable cantidad.
    */
    int* Persona::getCantidad(){
        return this->cantidad;
    }

   /**
    * Imprime la lista de teléfonos que ha comprado el usuario, y el monto de cada teléfono que ha
    * comprado el usuario
    */
    void Persona::verComprados(){

        if (comprados->estaVacio()) cout<< " ningun celular todavia"<<endl;
            else{
                    
                NodoDC<Celular*> *nimpreso = comprados->obtenerPrimero();
                int cont = 0;

                while(cont < comprados->obtenerLongitud()){

                    cout<< nimpreso -> toString()<< " con ";

                    /*
                    for(int i = 0; i < 10; i++){
                        cout<< cantidad[i] << " "<<endl;
                    }
                    */

                    cout<< cantidad[cont] << " items de este tipo\n" <<endl;

                    nimpreso = nimpreso->getSiguiente();
                    cont++;
                }

            }
    }

    //Metodos
    //Gests
    /**
     * Devuelve el nombre de la persona.
     * 
     * Returns
     * -------
     * 	El nombre de la persona.
     */
    string Persona::getNombre(){
        return nombre;

    }

   /**
    * Esta función devuelve el valor de la variable privada apellido
    * 
    * Returns
    * -------
    * 	el valor de la variable apellido.
    */
    string Persona::getApellido(){
        return apellido;
    }

    /**
     * Esta función devuelve el valor de la variable privada presupuesto
     * 
     * Returns
     * -------
     * 	El valor de la variable presupuesto.
     */
    double Persona ::getPresupuesto(){
        return presupuesto;
    }

    /**
     * Devuelve la lista de teléfonos que ha comprado la persona.
     * 
     * Returns
     * -------
     * 	Un puntero a aListDobleC<Mobile*>
     */
    ListaDobleC<Celular*>*  Persona ::getComprados(){
        return comprados;
    }

    //Setter
  /**
   * Esta función establece el valor de la variable privada nombre al valor del parámetro _nombre
   * 
   * Parameters
   * ----------
   * _nombre : string
   * 	Este es el parámetro que se pasa a la función.
   */
    void Persona ::setNombre(string _nombre){
        nombre = _nombre;

    }

  /**
   * Esta función iguala el valor de la variable privada presupuesto al valor del parámetro
   * _presupuesto
   * 
   * Parameters
   * ----------
   * _presupuesto : double
   * 	La cantidad de dinero que tiene la persona.
   */
    void Persona ::setPresupuesto(double _presupuesto){
        presupuesto = _presupuesto;

    }

    /**
     * *|CURSOR_MARCADOR|*
     * 
     * Parameters
     * ----------
     * list : ListaDobleC<Celular*>
     * 	Un puntero a un objeto ListaDobleC.
     */

    void Persona :: setComprados(ListaDobleC<Celular*>*list){
        comprados = list;

    }

   /**
    * Esta función devuelve una cadena con el nombre, apellido, presupuesto, id y correo electrónico de
    * la persona
    * 
    * Returns
    * -------
    * 	Una cadena con el nombre, apellido, presupuesto, id y correo electrónico de la persona.
    */
    string Persona::toString(){
        
        string s =  this->getNombre() + " " + this->getApellido() + ", tiene un presupuesto de " + to_string(this->getPresupuesto()) + ", de cedula " + this->getCedula() + " y su correo es " + this->getCorreo() + "\n";
        return s;
    }

   /**
    * Compara dos objetos de la clase Persona.
    * 
    * Parameters
    * ----------
    * c : Persona
    * 	Persona &c
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Persona::operator ==(Persona &c){

        double delta = 0.01;
        //cout<< abs(this->getPresupuesto()-c.getPresupuesto()) <<endl;
        return (this->getNombre() == c.getNombre()) && (this->getApellido() == c.getApellido()) && (abs(this->getPresupuesto()-c.getPresupuesto()) < delta && verificarDosChars(this->cedula, c.getCedula()));
    }

    bool Persona::verificarDosChars(char* a,char* b){
        int p = 0;
        int e = 0;

        while(e == 0){

        for(int o = 0; o < 11; o++){
            if(a[o] == b[o]){
                p++;
                //cout << "Entro condicion" <<endl;
            }
        }

        e++;

        }
        return p>9;
    }

    /**
     * Comprueba si el correo electrónico está vacío.
     * 
     * Returns
     * -------
     * 	un valor booleano.
     */
    bool Persona::tieneCorreo(){
        return this->getCorreo() != " ";
    }