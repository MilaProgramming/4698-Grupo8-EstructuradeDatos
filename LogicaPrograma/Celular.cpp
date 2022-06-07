#pragma once
#include "Celular.h"
#include <iostream>
#include <string>
using namespace std;

Celular::Celular(){

}

 //Gests
string Celular :: getMarca(){
    return marca;
}
double Celular ::getPrecio(){
    return precio;
}
int Celular ::getStock(){
    return stock;
}
bool Celular ::getExistencia(){
    return existe;
}

//Sets

void Celular :: setMarca(string _marca){
    marca = _marca;

}
void Celular ::setPrecio(double _precio){
    precio = _precio;
}
void Celular ::setStock(int _stock){
    stock = _stock;
}
void Celular ::setExistencia(bool _existe){
    existe = _existe;
}