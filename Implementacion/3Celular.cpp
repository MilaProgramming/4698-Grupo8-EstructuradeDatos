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
#include "3Celular.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

    /**
     * @param m
     * @param p
     * @param s
     */
    Celular::Celular(string m, double p, int s){
        this->marca = m;
        this->precio = p;
        this->stock = s;
    }


   /**
    * Celular::Celular() es una función que crea un nuevo objeto Celular
    */
    Celular::Celular(){

    }

   /**
    * El destructor es una función miembro que se llama cuando se destruye un objeto.
    */
    Celular::~Celular(){
        free(this);
    }

    /**
     * @return getMarca
     */
    //Gests
    string Celular :: getMarca(){
        return marca;
    }


    /**
     * @return getPrecio
     */
    double Celular ::getPrecio(){
        return precio;
    }

    /**
     * @return getStock
     */
    int Celular ::getStock(){
        return stock;
    }



    //Sets

    /**
     * Incrementa el stock del celular en la cantidad de c.
     * 
     * Parameters
     * ----------
     * c : int
     * 	la cantidad de stock a añadir
     */
    void Celular ::aumentarStock(int c){
        this->stock += c;
    }

    
   /**
    * Esta función establece el valor de la variable privada marca al valor del parámetro _marca
    * 
    * Parameters
    * ----------
    * _marca : string
    * 	La marca del teléfono.
    */
    void Celular :: setMarca(string _marca){
        marca = _marca;

    }

   
   /**
    * Esta función establece el valor de la variable privada precio al valor del parámetro _precio
    * 
    * Parameters
    * ----------
    * _precio : double
    * 	El precio del teléfono.
    */
    void Celular ::setPrecio(double _precio){
        precio = _precio;
    }

    
   /**
    * Esta función establece el stock del celular
    * 
    * Parameters
    * ----------
    * _stock : int
    * 	El stock del celular.
    */
    void Celular ::setStock(int _stock){
        stock = _stock;
    }

   
    /**
     * Disminuye el stock del artículo en 1.
     * 
     * Returns
     * -------
     * 	un valor booleano.
     */
    bool Celular::disminuirStock(){
        
        if(stock > 0){
            --stock; 
            return true;
        }else{
            cout<< "Ya no existe este item en el stock" <<endl;
            return false;
        }
    }


   
   /**
    * Si la cantidad es 1, entonces llama a la otra función; de lo contrario, si la acción es mayor que
    * 0 o la acción menos la cantidad es mayor que 0, entonces establece la acción en la acción menos
    * la cantidad y devuelve verdadero; de lo contrario, imprime un mensaje y devuelve falso
    * 
    * Parameters
    * ----------
    * cantidad : int
    * 	La cantidad de artículos que se eliminarán del stock.
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Celular::disminuirStock(int cantidad){

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


    /**
     * @param 
     * @return disminuirStock
     */
    string Celular::toString(){
        string t = "Marca = " + this->getMarca() + "\nPrecio = " + to_string(this->getPrecio()) + "\n";
        return t;
    }


    /**
     * La función devuelve verdadero si los dos objetos tienen la misma marca y la diferencia entre sus
     * precios es menor a 0.01
     * 
     * Parameters
     * ----------
     * c : Celular
     * 	Célula
     * 
     * Returns
     * -------
     * 	un valor booleano.
     */
    bool Celular::operator ==(Celular &c){
        double delta = 0.01;
            return this->getMarca() == c.getMarca() && abs(this->getPrecio() - c.getPrecio()) < delta;
    }

   
   /**
    * La función devuelve verdadero si el valor absoluto de la diferencia entre num1 y num2 es menor
    * que deltaMax
    * 
    * Parameters
    * ----------
    * num1 : double
    * 	El primer número a comparar.
    * num2 : double
    * 	El número a comparar.
    * deltaMax : double
    * 	La diferencia máxima entre los dos números.
    * 
    * Returns
    * -------
    * 	un valor booleano.
    */
    bool Celular::iguales (double num1, double num2, double deltaMax) {
        return (abs(num1 - num2) < deltaMax);
    }