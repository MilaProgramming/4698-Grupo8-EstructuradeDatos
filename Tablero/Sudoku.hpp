#include <iostream>
#include <fstream>
#include <string.h>
#include "../Graficos/posicion.hpp"
#include "../Graficos/color.hpp"
using namespace std;
#pragma once
   
class Sudoku{
    private:
        int longitudTablero{9};
        int **sudoku;
        Posicion p;

        //!Metodos para verificar

        bool estaEnFila(int fila, int num, int **tablero){

            for(int i = 0; i < longitudTablero; i++){

                if(*(*(tablero + fila)+i) == num)
                    return true;

            }

            return false;
        }

        bool estaEnColumna(int col, int num, int **tablero){

            for(int i = 0; i < longitudTablero; i++){

                if(*(*(tablero + i)+ col) == num)
                    return true;

            }

            return false;
        }
        
        bool estaEnSeccion(int fila, int col, int num, int **tablero){
            
            int filaInicial = fila - fila % 3;
            int colaInicial = col - col % 3;
   
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (tablero[i + filaInicial][j + colaInicial] == num)
                        return true;
        
            return false;

        }

        bool esPosible(int fila, int col, int num, int **tablero){
            return !(estaEnFila(fila,num, tablero)) && !(estaEnColumna(col,num, tablero)) && !(estaEnSeccion(fila,col,num, tablero));
        }

        void numeroPosibles(int *array){
            //int*ola = new;
            //rellena
            //devuelve el vector
        }

        bool solucionarSudoku(int **tablero, int fila, int col){

            // Checamos si ya hemos recorrido todas las filas.
            if (fila == longitudTablero - 1 && col == longitudTablero)
                return true;
        
            // Su el valor de la columna es 9, seguimos a la siguiente fila.
            if (col == longitudTablero) {
                fila++;
                col = 0;
            }
        
            // Si la posicion actual ya tiene un valor no vacio, seguir a la siguiente posicion
            if (tablero[fila][col] > 0)
                return solucionarSudoku(tablero, fila, col + 1);
        
            for (int num = 1; num <= longitudTablero; num++){
                
                // Chequear los numero de 1 al 9.
                if (esPosible(fila, col, num, tablero))
                {
                    
                // Asigno el numero y asumo que esta bien
                    tablero[fila][col] = num;
                
                    //  Checo por la siguiente solucion
                    if (solucionarSudoku(tablero, fila, col + 1))
                        return true;
                }
            
                // Si llego aca, significa que mi asuncion
                //es incorrecta. Asigno cero y paso pagina.
                tablero[fila][col] = 0;
            }
            
            return false;

        }

        void leerSudoku(string nombre){

            ifstream archivo(nombre);

            if (!(archivo.is_open())){
                cout << "Error al leer datos" << endl;
                return;
            }
                
            for (int i = 0; i < longitudTablero; i++){
                for (int j = 0; j < longitudTablero; j++){

                    archivo >> sudoku[i][j];  
                }
            }

            // for (int i = 0; i < longitudTablero; i++){
            //     for (int j = 0; j < longitudTablero; j++){

            //         cout << sudoku[i][j] << " ";  
            //     }

            //     cout << endl;
            // }

            archivo.close();
        }

        void leerSudokuP(string nombre){

            ifstream archivo(nombre);
      
            if (!(archivo.is_open())){
                cout << "Error al leer datos" << endl;
                return;
            }
            
            cout << archivo.rdbuf();
            
            archivo.close();
        }

        void imprimirBorde(){
            cout << "+-----------------------------------+"<<endl;
        }

        void imprimirSeparadorSeccion(){
            cout << "|-----------+-----------+-----------|"<<endl;
        }

        void imprimirSeparador(){
            cout << "|---+---+---|---+---+---|---+---+---|"<<endl;
        }

    public:

    Sudoku(string nombre): longitudTablero(9), sudoku(new int*[longitudTablero]){

        for(int i = 0; i < longitudTablero; i++)
            *(sudoku + i) = new int[longitudTablero];

        leerSudoku(nombre);
    }
    
    ~Sudoku(){
    }

    void imprimirSudoku(int ** array){
        
        imprimirBorde();

            for(int i = 0; i<longitudTablero; i++){
                cout<<"|";
                for(int j = 0; j < longitudTablero; j++){
                    int algo{*(*(array + i) + j)};

                    if(algo == 0){
                        cout<< " " << " " << " |";
                    }else{
                        cout<< " " << algo << " |";
                    }
                }

                cout<<endl;
                //cout << i << " i "<<endl;
                if (i == 2 || i == 5){
                    imprimirSeparadorSeccion();
                }else if(i != longitudTablero-1){
                    imprimirSeparador();
                }
            }

        imprimirBorde();

    }

    void imprimirIndicaciones(){

        p.irHacia(60,2);
        cout << "+--------+" <<endl;
        p.irHacia(60,3);
        cout << "| " << dye::white('S') + dye::light_red('u') + dye::white('d') + dye::light_red('o') + dye::white('k') + dye::light_red('u') << " |" <<endl;
        p.irHacia(60,4);
        cout << "+--------+"<<endl;
        p.irHacia(60,5);
        cout << endl;
        p.irHacia(42,6);
        cout << "+------------------------------------------------+"<<endl;
        p.irHacia(42,7);
        cout << "|    					  	   |"<<endl;
        p.irHacia(42,8);
        cout << "|	    Bienvenido al juego del sudoku!	   |"<<endl;
        p.irHacia(42,9);
        cout << "|    					  	   |"<<endl;
        p.irHacia(42,10);
        cout << "|     Recuerda que para ganar se debe llenar	   |"<<endl;
        p.irHacia(42,11);
        cout<< "|   todos los espacios vacios" << dye::light_red(" sin") << " repetir los	   |"<<endl;
        p.irHacia(42,12);
        cout << "|    numeros del" << dye::light_red(" 1") << " al" << dye::light_red(" 9")<< ", en las filas, columnas  |"<<endl;
        p.irHacia(42,13);
        cout << "|          y respectivas secciones.		   |"<<endl;
        p.irHacia(42,14);
        cout << "|    					  	   |"<<endl;
        p.irHacia(42,15);
        cout<< "|	            Mucha suerte!		   |"<<endl;
        p.irHacia(42,16);
        cout << "|    					  	   |"<<endl;
        p.irHacia(42,17);
         cout << "+------------------------------------------------+"<<endl;

    }

    void solucionar(){

        //imprimirSudoku(sudoku);
        if(solucionarSudoku(sudoku, 0, 0)){
            imprimirSudoku(sudoku);
        }else{
            cout << " ~ No existe solucion ~" <<endl;
        }

    }
};