/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#pragma once
#include <string>
#include "2ItoString.hpp"

class Celular: public ToString {
    private:
        string marca;
        double precio;
        int stock;

    public:

            /**
         * @param 
         * @param 
         * @param
         */
        Celular(string, double, int);
        Celular();
        ~Celular();

        //Getters y setters

        string getMarca();
        double getPrecio();
        int getStock();
       
          /**
         * @param string
         */
        void setMarca(string);
          /**
         * @param double
         */
        void setPrecio(double);
        /**
         * @param int
         */
        void setStock(int);
        /**
         * @param int
         */
        void aumentarStock(int);

        bool disminuirStock();

        /**
         * @param int
         */
        bool disminuirStock(int);
        string toString();

        /**
         * @param &Celular
         */
        bool operator ==(Celular&);

         /**
         * @param *Celular
         */
        bool operator ==(Celular*);

        /**
         * @param num1
         * @param num2
         * @param deltaMax
         */
        bool iguales (double num1, double num2, double deltaMax);
        

};