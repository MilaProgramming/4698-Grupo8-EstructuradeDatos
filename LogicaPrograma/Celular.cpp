#pragma once
#include "Celular.h"
#include <iostream>
#include <string>
using namespace std;

    Celular::Celular(string m, double p, int s){
        this->marca = m;
        this->precio = p;
        this->stock = s;
    }

    Celular::~Celular(){
        free(this);
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