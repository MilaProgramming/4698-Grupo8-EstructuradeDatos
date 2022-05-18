/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


#include "NumeroA.cpp"

int main ()

{   NumeroA n1(2) , n2(23), n3(62), n4(96);
     n2+=n2;
     cout << "Numero " << n2.getNumeroA() << endl;

     n3+=n3;
     cout << "Numero " << n3.getNumeroA() << endl;
    return 0;

}

