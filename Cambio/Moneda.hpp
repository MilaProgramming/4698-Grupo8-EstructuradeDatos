#include <iostream>
using namespace std;
#pragma once
   
class Moneda{
    private:
        float valor;
        int cantidad{0};

    public:
      Moneda(float valor, int cantidad): valor(valor), cantidad(cantidad){

      }
      
      Moneda(){
      }

      ~Moneda(){
      }

      int getCantidad(){
        return this->cantidad;
      }

      void disminuirCantidad(){
        this->cantidad--;
      }

      void reiniciarCantidad(){
        this->cantidad = 0;
      }

      void disminuirCantidad(int v){
        this->cantidad = cantidad - v;
      }

      void aumentarCantidad(){
        this->cantidad++;
      }

      void aumentarCantidad(int v){
        this->cantidad = cantidad + v;
      }

      float getValor(){
        return this->valor;
      }

      bool estaAgotado(){
        return this->cantidad == 0;
      }

      bool operator == (Moneda dos){
        return this->getValor() == dos.getValor();
      }

};