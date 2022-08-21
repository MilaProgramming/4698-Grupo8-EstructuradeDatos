#include <iostream>
#include "Tablero/Sudoku.hpp"
#include "Graficos/posicion.hpp"
using namespace std;

int main(){
    
    Sudoku s("Sudokus/sudoku.txt");
    s.empezar();
    Posicion p;
    p.irHacia(4,4);
    cout << "M" <<endl;
    p.irHacia(0,29);
    cout<< " ";

    return 0;
}
