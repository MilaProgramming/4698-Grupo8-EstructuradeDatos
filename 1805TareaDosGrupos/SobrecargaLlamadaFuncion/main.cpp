#include <iostream>
#include <iomanip>   // Para usar los manipuladores
#include <string.h>
#include "ListaPalabras.cpp"
#include "Acceso.cpp"
using namespace std;
// Cuenta las veces cada palabra en el texto

int main (void)
{
    char palabra[81];             // Cadena de caracteres para contener una palabra
    ListaPalabras listaPalabras1 (100); // Lista de palabras y contadores asociados

    cout << "Introducir texto. Finalizar con * en una linea:\n\n";
    cin >> palabra;

    while (strcmp(palabra, "*")) {
        listaPalabras1[palabra]++;
        cin >> palabra;
        cout << palabra << "\n";
    }

    Acceso siguiente (listaPalabras1);
    elementos *pLista;

    // Escribe la lista de palabras

    cout << "PALABRA        CONTADOR\n";
    while (pLista = siguiente()) {         // Llamada a la funcion operator()()
        cout << setiosflags (ios::left);   // Activa indicador ajuste izquierda
        cout << setw (15) << pLista->palabra; // Establece anchura del campo a 15
        cout << resetiosflags (ios::left); // Desactiva indicador ajuste izquierda
        cout << setw (4) << pLista->contador  // Establece anchura del campo a 4
             << endl;
    }

    return 0;
}