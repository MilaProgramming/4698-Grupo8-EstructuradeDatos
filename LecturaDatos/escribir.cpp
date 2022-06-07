#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

   ofstream file_out("archivo.txt", ios::app);
   int num = 1;

   for (int fila = 0; fila < 3; ++fila) {
      for (int columna = 0; columna < 3; ++columna) {
          file_out << num << " ";
          num++;
      }
      file_out << "\n";
   }

   file_out.close();
   return 0;
}
