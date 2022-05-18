#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
using namespace std;

class A
{    int a;
   public:
     friend int P(A);
     void defineA(int);
     int dameA(void);
};