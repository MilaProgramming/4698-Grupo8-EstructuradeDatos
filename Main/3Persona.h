#include <iostream>
#include <string>
#include "3Celular.cpp"
#include "1ListaDC.hpp"
#include "2ItoString.h"
using namespace std;

class Persona: public ToString{
    private:
        string nombre;
        string apellido;
        double presupuesto;
        string correo;
        ListaDobleC<Celular*> *comprados = new ListaDobleC<Celular*>();     
        int* cantidad = new int[50]; 

    public:

        Persona(string, string, double);
        Persona();
        ~Persona();

        void comprarCelular(Celular*); //Comprar un celular a su nombre
        bool verificarCelular(Celular*);
        void comprarCelular(Celular*, int); 
        bool disminuirPresupuesto();
        void verComprados(); //Ver que celulares ha comprado la persona en cuestion

        //Getter y setters
        string getNombre();
        string getApellido();
        double getPresupuesto();
        ListaDobleC<Celular*>* getComprados();
        string getCorreo();
        void setCorreo(string);

        //Operadores
        bool operator ==(Persona&);

        void setNombre(string);
        void setPresupuesto(double);
        void setComprados(ListaDobleC<Celular*>*);
        string toString();
};