#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
#include "A.h"
using namespace std;

class B
{    int b;
   public:
     friend int P(A);
     void defineB(int);
     int dameB(void);
};