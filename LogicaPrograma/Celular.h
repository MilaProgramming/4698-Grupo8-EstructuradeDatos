#pragma once
#include <string>
#include "ItoString.h"

class Celular: public ToString {
    private:
        string marca;
        double precio;
        int stock;

    public:
        Celular(string, double, int);
        Celular();
        ~Celular();

        //Getters y setters

        string getMarca();
        double getPrecio();
        int getStock();
   

        void setMarca(string);
        void setPrecio(double);
        void setStock(int);
        string toString();
      
        

};