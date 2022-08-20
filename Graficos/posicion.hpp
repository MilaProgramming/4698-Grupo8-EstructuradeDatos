#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
   
class Posicion{
    private:
        
    public:

    Posicion(){
    }
    
    ~Posicion(){
    }

    void irHacia(int x, int y){

        COORD screen;
        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        screen.X = x;
        screen.Y = y;
        SetConsoleCursorPosition(hOutput, screen);

    }

};