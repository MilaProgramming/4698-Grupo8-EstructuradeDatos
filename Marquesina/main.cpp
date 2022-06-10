#include <iostream>
#include <thread>
using namespace std;
#include "Marquesina.hpp"
#include <windows.h>



int main(){

    Marquesina<char> *a = new Marquesina<char>("Mesa que mas aplauda");
    a->bucleMarquesina();

    return 0;
}


