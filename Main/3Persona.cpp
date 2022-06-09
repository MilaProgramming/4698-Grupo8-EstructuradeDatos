#pragma once
#include "3Persona.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
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

        //cout<< "entro a comprar celu" <<endl;
        //!verifico si he comprado el celu antes
        if(verificarCelular(celu)){
            //cout<< "1 if" <<endl;
            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                //cout<< "2 if" <<endl;
                if(this->presupuesto - celu->getPrecio() > 0){
                    cout<< "3 if" <<endl;
                    if(celu->disminuirStock()){
                       //cout<< "4 if" <<endl;
                        this->presupuesto -= celu->getPrecio();

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
                //cout<< "No posee el suficiente dinero para comprar esto" <<endl;   
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
                        cout<< cantidad[aux] <<endl;
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
    
    void Persona::comprarCelular(Celular* celu, int cant){

      //!verifico si he comprado el celu antes
        if(verificarCelular(celu)){
            //out<< "1 if" <<endl;
            //!verifico si mi presupuesto es mayor que 0
            if(disminuirPresupuesto()){
                //cout<< "2 if" <<endl;
                if(this->presupuesto - ((celu->getPrecio())*cant) > 0){

                    if(celu->disminuirStock()){
                        //cout<< "4 if" <<endl;
                        this->presupuesto -= celu->getPrecio();

                        this->comprados->insertarFinal(celu);
                        cantidad[comprados->obtenerLongitud()-1] += cant;

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

                    for(int i = 0; i < 10; i++){
                        cout<< cantidad[i] << " "<<endl;
                    }

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
        string s =  this->getNombre() + " " + this->getApellido() + ", tiene un presupuesto de " + to_string(this->getPresupuesto()) + " y su correo es " + this->getCorreo() + "\n";
        return s;
    }

    bool Persona::operator ==(Persona &c){

        double delta = 0.01;
        //cout<< abs(this->getPresupuesto()-c.getPresupuesto()) <<endl;
        return (this->getNombre() == c.getNombre()) && (this->getApellido() == c.getApellido()) && (abs(this->getPresupuesto()-c.getPresupuesto()) < delta);
    }

    bool Persona::tieneCorreo(){
        return this->getCorreo() != " ";
    }