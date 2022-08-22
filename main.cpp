#include <iostream>
#include <conio.h>
#include "Tablero/Sudoku.hpp"
#include "Graficos/posicion.hpp"
using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESPACIO 32
#define ESCAPE 27
#define BACKSPACE 8


int main(){
    
    Sudoku s("Sudokus/sudoku.txt");
    Posicion p(0,12);
    s.empezar();

    char c;
    while(true){

        c=getch(); //Recibo el dato por teclado

        switch (c)
        {
        case ARRIBA:
            s.irArriba();
            break;
        
        case ABAJO:
            s.irAbajo();
            break;

        case IZQUIERDA:
            s.irIzquierda();
            break;
        
        case DERECHA:
            s.irDerecha();
            break;
        
        case ESPACIO:
            s.pista();

            if(s.gano()){
                p.irHacia();
                return 0;
            }
            
            break;

        case BACKSPACE:
            s.borrar();
            break;
        
        case ESCAPE:
            s.salir();   
            p.irHacia();
            return 0;

        default:

            if(c >= 49 && c <= 57){

                s.asignar(c-48);

                if(s.gano()){
                    p.irHacia();
                    return 0;
                }
            }

            break;
        }

    }

    return 0;
}
