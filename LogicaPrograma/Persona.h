#include <iostream>
#include <string>
#include "Celular.h"
#include "ListaDC.hpp"

using namespace std;

class Persona{
    private:
        string nombre;
        double presupuesto;
        ListaDobleC<Celular> *comprados = new ListaDobleC<Celular>();     

    public:

        Persona(string, double);
        ~Persona();
        void comprarCelular();
        void verComprados();

        //Getter y setters
        string getNombre();
        double getPresupuesto();
        ListaDobleC<Celular>* getComprados();

        void setNombre(string);
        void setPresupuesto(double);
        void setComprados(ListaDobleC<Celular>*);

};