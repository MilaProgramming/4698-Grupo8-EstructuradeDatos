#include <iostream>
#include "Tablero/Sudoku.hpp"
#include "Graficos/posicion.hpp"
using namespace std;

int main(){
    
    Sudoku s("Sudokus/sudoku.txt");
    s.solucionar();
    Posicion p;
    p.irHacia(45,5);
    s.imprimirIndicaciones();
    p.irHacia(0,20);
    cout<< " ";

    return 0;
}
