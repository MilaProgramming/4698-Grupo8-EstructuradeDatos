#include <iostream>
#include "Tablero/Sudoku.hpp"
#include "Graficos/posicion.hpp"
using namespace std;

int main(){
    
    Sudoku s("Sudokus/sudoku.txt");
    s.empezar();
    s.irDerecha();
    s.pausar();
    s.irAbajo();
    s.pausar();
    s.irAbajo();
    s.pausar();
    s.irIzquierda();
    s.pausar();
    s.irArriba();
    s.pausar();
    Posicion p(0,12);
    p.irHacia();

    

    return 0;
}
