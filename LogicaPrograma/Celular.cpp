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

    Celular::Celular(){

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

    int Celular ::getCantidad(){
        return this->cantidad;
    }

    //Sets

    void Celular ::setCantidad(int c){
        this->cantidad = c;
    }

    void Celular ::aumentarCantidad(int c){
        this->cantidad += c;
    }

    void Celular :: setMarca(string _marca){
        marca = _marca;

    }

    void Celular ::setPrecio(double _precio){
        precio = _precio;
    }

    void Celular ::setStock(int _stock){
        stock = _stock;
    }

    bool Celular ::disminuirStock(){
        if(stock > 0){
        --stock; 
        return true;
        }else{
            cout<< "Ya no existe este item en el stock" <<endl;
            return false;
        }
    }

    bool Celular ::disminuirStock(int cantidad){

        if (cantidad == 1){
            return disminuirStock();
        }else if(stock > 0 || stock - cantidad > 0){
            stock = stock - cantidad; 
            return true;
        }else{
            cout<< "No existen tantos items en el stock" <<endl;
            return false;
        }
    }

    string Celular::toString(){
        string t = "El celular, de la marca " + this->getMarca() + ", y de precio " + to_string(this->getPrecio());
        return t;
    }

    bool Celular::operator ==(Celular* c){
        return this->getCantidad() == c->getCantidad() && this->getMarca() == c->getMarca() && this->getPrecio() == c->getPrecio() && this->getStock() == c->getStock();
    }
