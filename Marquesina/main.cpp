#include <iostream>
using namespace std;
#include "Marquesina.hpp"

int main(){

    Marquesina<char> *a = new Marquesina<char>("Me quiero cambiar de carrera");

    a->bucleMarquesina();

    return 0;
}