#include "Ej8.h"

Quebrado Quebrado::operator +(Quebrado &Q1, Quebrado &Q2)
{    Quebrado Aux;
     Aux.numerador = Q1.numerador * Q2.denominador +
                     Q2.numerador * Q1.denominador;
     Aux.denominador = Q1.denominador * Q2.denominador;
     return Aux;
}
