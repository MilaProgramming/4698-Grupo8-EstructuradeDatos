#include <iostream>
using namespace std;
#include "Calculadora.hpp"

int main(){

    Calculadora<float> *c = new Calculadora<float>();
    float *array = c ->convertirRealenFraccion(0.333);

    cout<< array[0] << "/" << array[1] <<endl;

    return 0;
}