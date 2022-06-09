#pragma once
#include "3Persona.h"
#include <iostream>
#include <string>
using namespace std;

    Persona::Persona(string n, string m, double p){
        this->nombre = n;
        this ->apellido = m;
        this->presupuesto = p;
    }

    Persona::~Persona(){
        delete [] cantidad;
        free(this);
    }

    Persona::Persona(){
    }

    void Persona::comprarCelular(Celular* celu){

        //!verifico si he comprado el celu antes
        if(verificarCelular(celu)){
            //out<< "1 if" <<endl;
            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                //cout<< "2 if" <<endl;
                if(this->presupuesto - celu->getPrecio() > 0){
                    //cout<< "3 if" <<endl;
                    if(celu->disminuirStock()){
                        //cout<< "4 if" <<endl;
                        this->presupuesto -= celu->getPrecio();

                        this->comprados->insertarFinal(celu);
                        cantidad[comprados->obtenerLongitud()-1] = 1;

                        cout<< "\n-- Compra realizada con exito --" <<endl;

                    }else{
                        //cout<< "3 if" <<endl;
                        celu->disminuirStock(); 
                    }

                }else{
                    //cout<< "5 if" <<endl;
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                } 

            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            } 

        }else{

            //!CASO CELULAR YA COMPRADO

            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){

                if(this->presupuesto - celu->getPrecio() > 0){

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
    
    void Persona::comprarCelular(Celular* celu, int cantidad){

        if(verificarCelular(celu)){
            if(disminuirPresupuesto()){
                if(this->presupuesto - celu->getPrecio()*cantidad > 0 ){
                    if(celu->disminuirStock(cantidad)){
                        this->presupuesto -= celu->getPrecio()*cantidad;
                        celu->aumentarCantidad(cantidad);
                        this->comprados->insertarFinal(celu);
                    }else{
                    celu->disminuirStock(cantidad);                
                    }    
                }else{
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl; 
                }  
            }else{
                cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
            }
        }else{

                if(disminuirPresupuesto()){
                    if(this->presupuesto - celu->getPrecio()*cantidad > 0){
                        if(celu->disminuirStock(cantidad)){
                            this->presupuesto -= celu->getPrecio()*cantidad;
                        
                            NodoDC<Celular*> *it =comprados->obtenerUltimo();

                            int cont = 0;
                            while(cont < comprados->obtenerLongitud()){
                                if(*(it -> getValor()) == *celu){
                                    (it->getValor())->aumentarCantidad(cantidad);
                                }
                                it = it->getAnterior();
                                cont++;
                            }
                        }else{
                        celu->disminuirStock(cantidad);  
                        }
                    }else{
                        cout<< "No posee el suficiente dinero para comprar esto" <<endl;                
                    }
                }else{
                    cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
                }
                    
        }    
    }

    
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

    bool Persona::disminuirPresupuesto(){
        if(this->presupuesto > 0){
            return true;
        }
        else return false;
    }

    string Persona::getCorreo(){
        return this ->correo;
    }
    
    void Persona::setCorreo(string c){
        this -> correo = c;
    }

    void Persona::verComprados(){

        if (comprados->estaVacio()) cout<< " ningun celular todavia"<<endl;
            else{
                    
                NodoDC<Celular*> *nimpreso = comprados->obtenerPrimero();
                int cont = 0;

                while(cont < comprados->obtenerLongitud()){

                    cout<< nimpreso -> toString()<< " con ";
                    cout<< cantidad[cont] << " items de este tipo\n" <<endl;

                    nimpreso = nimpreso->getSiguiente();
                    cont++;
                }

            }
    }

    //Metodos
    //Gests
    string Persona::getNombre(){
        return nombre;

    }

    string Persona::getApellido(){
        return apellido;
    }

    double Persona ::getPresupuesto(){
        return presupuesto;
    }

    ListaDobleC<Celular*>*  Persona ::getComprados(){
        return comprados;
    }

    //Setter
    void Persona ::setNombre(string _nombre){
        nombre = _nombre;

    }

    void Persona ::setPresupuesto(double _presupuesto){
        presupuesto = _presupuesto;

    }
    void Persona :: setComprados(ListaDobleC<Celular*>*list){
        comprados = list;

    }

    string Persona::toString(){
        string s =  this->getNombre() + " " + this->getApellido() + ", tiene un presupuesto de " + to_string(this->getPresupuesto());
        return s;
    }

    bool Persona::operator ==(Persona &c){

        return this->getNombre() == c.getNombre() && this->getApellido() == c.getApellido();
    }