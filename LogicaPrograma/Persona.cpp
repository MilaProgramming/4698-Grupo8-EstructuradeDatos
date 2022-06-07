#pragma once
#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

    Persona::Persona(string n, double p){
        this->nombre = n;
        this->presupuesto = p;
    }

    Persona::~Persona(){
        free(this);
    }

    void Persona::comprarCelular(Celular celu){
        this->comprados->insertarInicio(celu);
    }

    void Persona::verComprados(){
        this->comprados->imprimirInicio();
    }

    //Metodos
    //Gests
    string Persona::getNombre(){
        return nombre;

    }
    double Persona ::getPresupuesto(){
        return presupuesto;
    }

    ListaDobleC<Celular>*  Persona ::getComprados(){
        return comprados;
    }

    //Setter
    void Persona ::setNombre(string _nombre){
        nombre = _nombre;

    }

    void Persona ::setPresupuesto(double _presupuesto){
        presupuesto = _presupuesto;

    }
    void Persona :: setComprados(ListaDobleC<Celular>*list){
        comprados = list;

    }

