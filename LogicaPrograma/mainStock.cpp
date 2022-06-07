#include <iostream>
using namespace std;
#include "Tienda.cpp"
#include "Celular.cpp"
#include "ListaDC.hpp"
#include "Persona.cpp"
#include "Stock.cpp"

int main(){

    Persona *p1 = new Persona("Maty", 300);
    Persona *p2 = new Persona("Mila", 1000);
    Persona *p3 = new Persona("Dami", 150);

   ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
   personas->insertarFinal(p1);
   personas->insertarFinal(p2);
   personas->insertarFinal(p3);

   Celular *c1 = new Celular("Coso", 300, 5);
   Celular *c2 = new Celular("Coso1", 400, 10);

    ListaDobleC<Celular*> *celulares = new ListaDobleC<Celular*>();
    celulares->insertarFinal(c1);
    celulares->insertarFinal(c2);

    p1->comprarCelular(c1);
    p2 ->comprarCelular(c2);
    p3 ->comprarCelular(c1);
    p3 ->comprarCelular(c2);

    Stock *stock = new Stock();
    stock->setCelulares(celulares);
    stock->setPersonas(personas);

    stock->informeCompraCelulares();
    cout<<"ver celulares"<<endl;
    stock-> verCelulares();
    cout<<"ver stock"<<endl;
    stock->verStock();
    cout<<"ver stock particular"<<endl;
    stock->verStock(c2);
    
    return 0;
}