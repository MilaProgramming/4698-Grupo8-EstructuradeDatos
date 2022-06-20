#include "1Pila.hpp"
#include <iostream>
#include "Proceso.cpp"
#include <regex>
using namespace std;
#include <cstring>


int main(){



   
    while(true){

        Proceso *p = new Proceso();
        p->recibirExpresion();
        p->convertirPostfija();
        p->resolver();

        delete p;
    }
   
 
    return 0;
}
