#include "Cadena.cpp"

int main ()
{    Cadena C1("Juan ") , C2("Lopez");
     C1+C2;
     cout << "Atributo de C1 = " << C1.DameCadena() << endl;

    return 0;
}
