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

#include <iostream>
#include <string>
#include "3Celular.cpp"
#include "1ListaDC.hpp"
#include "2ItoString.h"
using namespace std;

class Persona: public ToString{

    private:
       /* Declarar las variables de la clase. */
        string nombre;
        string apellido;
        double presupuesto;
        unsigned long cedula;
        string correo = " ";
        ListaDobleC<Celular*> *comprados = new ListaDobleC<Celular*>();     
        int* cantidad = new int[50]; 

    public:

       /* un constructor */
        Persona(string, string, double, unsigned long);
        /* Un constructor que toma una cadena, una cadena y un largo. */
        Persona(string, string, long);
        /* Un constructor que no acepta argumentos. */
        Persona(void);
       /* Un destructor. */
        ~Persona();

        void comprarCelular(Celular*); //Comprar un celular a su nombre
       /* Comprobando si la persona ha comprado el teléfono. */
        bool verificarCelular(Celular*);
       /* Un método que le permite comprar un teléfono celular. */
        void comprarCelular(Celular*, int); 
        /* Un método que disminuye el presupuesto de la persona. */
        bool disminuirPresupuesto();
        void verComprados(); //Ver que celulares ha comprado la persona en cuestion

        //Getter y setters
        string getNombre();
        /* Un método captador. */
        string getApellido();
       /* Un método captador. */
        double getPresupuesto();
        /* Devolver un puntero a un objeto ListaDobleC. */
        ListaDobleC<Celular*>* getComprados();
     /* Un método captador. */
        string getCorreo();
        /* Un método captador. */
        unsigned long getCedula();
        /* Fijación de la cédula de la persona. */
        void setCedula(unsigned long);
        /* Configuración del correo electrónico de la persona. */
        void setCorreo(string);
       /* Un método que verifica si la persona tiene un correo electrónico. */
        bool tieneCorreo();
        /* Devolviendo un puntero int. */
        int* getCantidad();

        //Operadores
        /* Comparación de dos objetos de la misma clase. */
        bool operator ==(Persona&);

        /* Un método setter. */
        void setNombre(string);
        /* Fijación del presupuesto de la persona. */
        void setPresupuesto(double);
       /* Configuración de la lista de teléfonos comprados. */
        void setComprados(ListaDobleC<Celular*>*);
        /* Un método que devuelve una cadena. */
        string toString();
};