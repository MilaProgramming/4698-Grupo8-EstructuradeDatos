#pragma once
#include <string>


class Celular{
    private:
        string marca;
        double precio;
        int stock;
        bool existe;
    public:
        Celular();
        ~Celular();

        //Getters y setters

        string getMarca();
        double getPrecio();
        int getStock();
        bool getExistencia();

        void setMarca(string);
        void setPrecio(double);
        void setStock(int);
        void setExistencia(bool);
        

};