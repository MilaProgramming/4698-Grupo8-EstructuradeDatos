#include <iostream>
#include <string>
#include "Celular.h"
#include "ListaDC.hpp"

using namespace std;

class Persona{
    private:
        string nombre;
        double presupuesto;
        ListaDobleC<Celular> *lista = new ListaDobleC<Celular>();     

    public:

        Persona();
        ~Persona();
        void comprarCelular();

        //Getter y setters
        string getNombre();
        double getPresupuesto();
        ListaDobleC<Celular>* getCelulares();

        void setNombre(string);
        void setPresupuesto(double);
        void setCelulares(ListaDobleC<Celular>*);

};