#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include "Lista.hpp"
#include "Nodo.hpp"

using namespace std;

void escribir(string filename, ListaEnlazada<string>* titulos, ListaEnlazada<ListaEnlazada<int>*>* datos){
 
    // Create an output filestream object
    ofstream myFile(filename);

    // Send column names to the stream
    Nodo<string> *n = new Nodo<string>();
    n = titulos->retornarPrimero();

    for(int j = 0; j < titulos->longitudLista(); ++j)
    {   

        myFile << n->getValor();
        if(j != titulos->longitudLista() - 1) myFile << ","; // No comma at end of line
        n = n->getNodo();
    }

    myFile << "\n";
    
    
    // Close the file
    myFile.close();
}

int main() {

    ListaEnlazada<int> *l1 = new ListaEnlazada<int>();
    ListaEnlazada<int> *l2 = new ListaEnlazada<int>();
    ListaEnlazada<int> *l3 = new ListaEnlazada<int>();

    // Make three vectors, each of length 100 filled with 1s, 2s, and 3s
    l1->agregarFinal(100);
    l1->agregarFinal(200);
    l1->agregarFinal(300);

    l2->agregarFinal(1);
    l2->agregarFinal(2);
    l2->agregarFinal(3);

    l3->agregarFinal(10);
    l3->agregarFinal(20);
    l3->agregarFinal(30);

    ListaEnlazada<string> *l4 = new ListaEnlazada<string>();
    l4->agregarFinal("Uno");
    l4->agregarFinal("Dos");
    l4->agregarFinal("Tres");

    ListaEnlazada<ListaEnlazada<int>*> *t = new ListaEnlazada<ListaEnlazada<int>*>();
    t->agregarFinal(l1);
    t->agregarFinal(l2);
    t->agregarFinal(l3);

    // Write the vector to CSV
    escribir("three_cols.txt", l4, t);
    
    return 0;
}