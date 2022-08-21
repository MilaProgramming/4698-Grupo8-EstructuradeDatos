#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Posicion{
    private:
        int col;
        int fil;

    public:

    Posicion(int col, int fil): col(col), fil(fil){
    }
    
    ~Posicion(){
    }

    void irHacia(int col, int fil){

        COORD screen;
        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        screen.X = col;
        screen.Y = fil;
        SetConsoleCursorPosition(hOutput, screen);

    }

    void irHacia(){

        COORD screen;
        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        screen.X = 4 + 4*col;
        screen.Y = 2 + 2*fil;
        SetConsoleCursorPosition(hOutput, screen);

    }

    int getCol(){
        return this->col;
    }

    int getFil(){
        return this->fil;
    }

    bool irDerecha(){

        if(col < 8){
            this-> col+=1;
            return true;
        }

        return false;
    }

    bool irIzquierda(){

        if(col > 0){
            this-> col-=1;
            return true;
        }

        return false;
    }

    bool irArriba(){
        
        if(fil > 0){
            this-> fil-=1;
            return true;
        }

        return false;

    }

    bool irAbajo(){

        if(fil < 8){
            this-> fil+=1;
            return true;
        }

        return false;
    }

    

};