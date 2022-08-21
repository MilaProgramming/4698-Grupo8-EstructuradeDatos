#include <iostream>
#include "Tablero/Sudoku.hpp"
#include "Graficos/posicion.hpp"
using namespace std;

int main(){
    
    Sudoku s("Sudokus/sudoku.txt");
    s.empezar();
    Posicion p(4,2);
    p.irHacia();
    cout << "M";
    p.irAbajo();
    p.irHacia();
    cout << "A";
    p.irDerecha();
    p.irHacia();
    cout << "T";
    p.irArriba();
    p.irHacia();
    cout << "T";
    p.irArriba();
    p.irHacia();
    cout << "Y";
    p.irIzquierda();
    p.irHacia();
    cout << "<3";

    p.irHacia(0,29);
    cout<< " ";

    return 0;
}
