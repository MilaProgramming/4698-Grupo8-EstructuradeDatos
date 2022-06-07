#pragma once
#include "Celular.h"
#include <iostream>
#include <string>
using namespace std;

    Celular::Celular(){

    }

    Celular::~Celular(){
        
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