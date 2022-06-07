#include <iostream>
using namespace std;
#include "ListaDC.hpp"

int main(){

    ListaDobleC<int> *lista = new ListaDobleC<int>();

    lista->insertarFinal(10);
    lista->insertarInicio(5);
    lista->insertarInicio(20);
   
    lista->insertar(2,2);
    lista->imprimirInicio();
    lista->revertir();
    lista->imprimirInicio();
    lista->ordenar();
    lista->imprimirInicio();

    return 0;
}