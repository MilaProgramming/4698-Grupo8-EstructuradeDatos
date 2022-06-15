
#include <iostream>
using namespace std;
#include "Pila.h"

int main(){

    Pila<int> *pila = new Pila<int>();
<<<<<<< HEAD
=======

    pila->apilar(1);
    pila->apilar(2);
    pila->apilar(3);
    pila->apilar(4);
    pila->apilar(5);
>>>>>>> d0931cf885421862ffce06a7be97f57ca635c25f
    pila->apilar(6);
    pila->apilar(5);
    pila->apilar(4);
    pila->apilar(3);
    pila->apilar(2);
    pila->apilar(1);
    
<<<<<<< HEAD
    pila->mostrar();

    pila->desapilar();
    pila->mostrar();
    pila->desapilar();
    pila->mostrar();
    pila->desapilar();
    pila->mostrar();
    pila->desapilar();
    pila->mostrar();
    pila->desapilar();

=======
>>>>>>> d0931cf885421862ffce06a7be97f57ca635c25f
    pila->mostrar();

    pila->desapilar();

    pila->mostrar();
    return 0;
}