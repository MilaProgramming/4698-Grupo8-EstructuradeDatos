#include <iostream>
using namespace std;
#include "3Tienda.cpp"
#include "3Celular.cpp"
#include "1ListaDC.hpp"
#include "3Persona.cpp"
#include "3Stock.cpp"

int main(){

    Persona *p1 = new Persona("Maty", 15);
    Persona *p2 = new Persona("Hola", 500);

    ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
    personas->insertarFinal(p1);


    Celular *c1 = new Celular("Coso1", 3000, 3);
    Celular *c3 = new Celular("Coso3", 10, 7);
    Celular *c2 = new Celular("Coso2", 400, 10);

    ListaDobleC<Celular*> *celulares = new ListaDobleC<Celular*>();
    celulares->insertarFinal(c1);
    celulares->insertarFinal(c3);
    celulares->insertarFinal(c2);
    

    Stock *stock = new Stock();
    stock->setCelulares(celulares);
    stock->setPersonas(personas);

    Tienda *tienda = new Tienda();
    tienda->setStock(stock);
    
    tienda->getStock()->getCelulares()->imprimirObjetoInicio();
    tienda->getStock()->ordenarPorPrecio();
    cout<< "\n";
    tienda->getStock()->getCelulares()->imprimirObjetoInicio();
    cout<< "\n";

    cout<<"2"<<endl;
    tienda->celularesPorPresupuestoMayor(2)->imprimirObjetoInicio();
    
    //cout<<"5"<<endl;
    //tienda->celularesPorPresupuestoMayor(5)->imprimirObjetoInicio();

    cout<<"5"<<endl;
    tienda->celularesPorPresupuestoMenor(5)->imprimirObjetoInicio();

    cout<<"7000"<<endl;
    tienda->celularesPorPresupuestoMenor(7000)->imprimirObjetoInicio();
    

    return 0;
}