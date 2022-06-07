#include <iostream>
using namespace std;
#include "Tienda.cpp"
#include "Celular.cpp"
#include "ListaDC.hpp"
#include "Persona.cpp"

int main(){

    Persona *c1 = new Persona("Maty", 300);
    Persona *c2 = new Persona("Mila", 1000);
    Persona *c3 = new Persona("Dami", 150);

   ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
   personas->insertarInicio(c1);
   personas->insertarInicio(c2);
   personas->insertarInicio(c3);
   
   personas->imprimirObjetoFinal(); 

    return 0;
}