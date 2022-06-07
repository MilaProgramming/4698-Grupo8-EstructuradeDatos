#include <iostream>
#include <string>
#include "Celular.cpp"
#include "ListaDC.hpp"
#include "ItoString.h"
using namespace std;

class Persona: public ToString{
    private:
        string nombre;
        double presupuesto;
        ListaDobleC<Celular*> *comprados = new ListaDobleC<Celular*>();     

    public:

        Persona(string, double);
        ~Persona();
        void comprarCelular(Celular*); //Comprar un celular a su nombre
        bool verificarCelular(Celular*);
        void comprarCelular(Celular*, int); 
        bool disminuirPresupuesto();
        void verComprados(); //Ver que celulares ha comprado la persona en cuestion

        //Getter y setters
        string getNombre();
        double getPresupuesto();
        ListaDobleC<Celular*>* getComprados();

        void setNombre(string);
        void setPresupuesto(double);
        void setComprados(ListaDobleC<Celular*>*);
        string toString();
};