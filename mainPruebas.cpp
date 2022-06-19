#include "1Pila.hpp"
#include <iostream>
#include "Proceso.cpp"
#include <regex>
using namespace std;
#include <cstring>


int main(){

    Proceso *p = new Proceso();

    while (true){
        p->recibirExpresion();
    }

    //p->convertirPostfija();
 
    return 0;
}
