#include <iostream>
using namespace std;
#include "ListaDC.hpp"

int main(){

    ListaDobleC<int> *lista = new ListaDobleC<int>();

    lista->insertar(10);
    lista->insertarInicio(5);
    lista->insertarInicio(0);
   
    lista->insertar(2,2);
    lista->imprimirInicio();
    
    return 0;
}