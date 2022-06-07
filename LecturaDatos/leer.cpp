#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

   ifstream file_in("archivo.csv");
   string num;
   int numero_filas, numero_columnas;
   file_in >> numero_filas >> numero_columnas;

   for (int fila = 0; fila < numero_filas; ++fila) {
      for (int columna = 0; columna < numero_columnas; ++columna) {
          file_in >> num;
          cout<< num;
      }
   }

   file_in.close();
   return 0;
}