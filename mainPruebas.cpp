#include "1Pila.hpp"
#include <iostream>
#include "Proceso.cpp"
using namespace std;

int main(){

    Proceso *p = new Proceso();

    p->recibirExpresion();

    return 0;
}
