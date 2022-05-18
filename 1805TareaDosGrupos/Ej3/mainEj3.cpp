/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


#include "Cadena.cpp"

int main ()
{    Cadena C1("Juan ") , C2("Lopez");
     C1+C2;
     cout << "Atributo de C1 = " << C1.DameCadena() << endl;

    return 0;
}
