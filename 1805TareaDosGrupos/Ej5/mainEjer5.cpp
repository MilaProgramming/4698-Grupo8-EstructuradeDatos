/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


#include "Ejer5.cpp"
  int main ()
   {
	 A A1(2),A2(3),A3;
     cout << "Inicialmente : " << endl;
     cout << "A1 : " << A1.DameX()<< endl;
     cout << "A2 : " << A2.DameX()<< endl;
     cout << endl;
    
     A3 = ++A1;
     cout << "Como prefijo A3 = ++A1 : " << endl;
     cout << "A1 : " << A1.DameX()<< endl;
     cout << "A3 : " << A3.DameX()<< endl;

     A3 = A2++;
     cout << endl;
     cout << "Como sufijo A3 = A2++: " << endl;
     cout << "A2 : " << A2.DameX()<< endl;
     cout << "A3 : " << A3.DameX()<< endl;
     return 0;
 	}


