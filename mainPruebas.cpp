#include "1Pila.hpp"
#include <iostream>
using namespace std;

int main(){

    Pila<int> *p = new Pila<int>();
    p->push(1);
    p->push(2);
    p->push(3);

    p->imprimir();

    return 0;
}
