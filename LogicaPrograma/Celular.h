#pragma once
#include <string>


class Celular{
    private:
        string marca;
        double precio;
        int stock;

    public:
        Celular(string, double, int);
        ~Celular();

        //Getters y setters

        string getMarca();
        double getPrecio();
        int getStock();
   

        void setMarca(string);
        void setPrecio(double);
        void setStock(int);
      
        

};