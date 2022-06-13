
#include <iostream>
using namespace std;
#include "Cola.hpp"

int main(){

    Cola<int> *cola = new Cola<int>();
    cola->insertar(1);
    cola->insertar(2);
    cola->insertar(3);
    cola->insertar(4);

    cola->imprimir();

    cola->eliminar();

    cola->imprimir();

    return 0;
}