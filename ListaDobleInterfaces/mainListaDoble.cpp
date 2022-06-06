#include <iostream>
#include "ListaD.hpp"
using namespace std;

int main(){

    ListaDoble<int> *lista = new ListaDoble<int>();

    lista->insertar(10);

    lista->insertarInicio(5);
    lista->insertarInicio(0);
    lista->insertarFinal(15);
    lista->insertarFinal(20);
    lista->imprimirInicio();

    lista->insertar1(2);

    lista->imprimirInicio();
    
    lista->insertar2(3);

    lista->imprimirInicio();


    
    return 0;
}