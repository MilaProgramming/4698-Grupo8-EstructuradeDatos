/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


#include "claseB.cpp"

int main()
{    B Ob;

     cout << "Ingrese datos :" << endl;
     while (1)
     {    int p;
          cin >> p;
          if (p<=0) break;
          Ob.Ingresa(p);
     }
     cout << "Datos leidos :" << endl;
     for (int i=0; i<Ob.DameCant(); i++)
     cout << Ob[i] << endl;

     return 0;
}
