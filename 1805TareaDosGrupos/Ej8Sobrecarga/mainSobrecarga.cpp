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
