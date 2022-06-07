#pragma once
#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

Persona::Persona(){}

Persona::~Persona(){}

void Persona::comprarCelular(){
    
}
 //Metodos
 //Gests
string Persona::getNombre(){
    return nombre;

}
double Persona ::getPresupuesto(){
    return presupuesto;
}

ListaDobleC<Celular>*  Persona ::getCelulares(){
    return lista;
}
//Sets
void Persona ::setNombre(string _nombre){
    nombre = _nombre;

}

void Persona ::setPresupuesto(double _presupuesto){
    presupuesto = _presupuesto;

}
void Persona :: setCelulares(ListaDobleC<Celular>*lista){
    lista = lista;

}

