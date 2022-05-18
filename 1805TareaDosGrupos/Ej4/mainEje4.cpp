/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


#include "Ejer4.cpp"

int main(){

    Complejo A(1.5,2.3), B(5.2,4.7), C(1.1,0.4), D;
     D= A + B - C;
     cout << "D = " << D.DameR()<<" + "<< D.DameI() << "i"
          << endl;
}
