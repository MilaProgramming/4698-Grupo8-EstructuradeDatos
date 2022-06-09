#include <iostream>
using namespace std;
#include "Marquesina.hpp"

int main(){

    Marquesina<char> *a = new Marquesina<char>("Mesa que mas aplauda");

    a->bucleMarquesina();

    return 0;
}
