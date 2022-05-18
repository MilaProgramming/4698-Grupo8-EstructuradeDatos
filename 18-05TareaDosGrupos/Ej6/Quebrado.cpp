#include "Quebrado.h"

Quebrado Quebrado::operator + (Quebrado &Q)
{    return Quebrado (numerador * Q.DameDen()+ Q.DameNum()* denominador , 
                      denominador * Q.DameDen());
}
