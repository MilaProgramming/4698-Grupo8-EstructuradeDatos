#include "A.cpp"
#include "B.cpp"

int main(void)
{    B Objeto;
     A Obj;
     Obj.defineA(2);
     Objeto.defineB(3);
     cout << Objeto.P(Obj) << endl;

     return 0; 
}