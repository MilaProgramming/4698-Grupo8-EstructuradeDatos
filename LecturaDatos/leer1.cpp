#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string f;
    cin >> f;
   ifstream file(f);

  
   string nombre;
   string apellido;
   double presupuesto;
   unsigned long cedula;
   
   while(file >> nombre >> apellido >> presupuesto >> cedula){
       cout<< nombre << ", " << apellido << ", " << presupuesto << ", " << cedula <<endl;
   }

   
   file.close();
   return 0;
}