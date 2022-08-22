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

    void transformarCoordenadas(){
        this->col =  4 + 4*col;
        this->fil = 2 + 2*fil;
    }

    void reiniciarCoordenadas(){
        this->col =  (col - 4)/4;
        this->fil = (fil-2)/2;
    }

    int getCol(){
        return this->col;
    }

    int getFil(){
        return this->fil;
    }

    void irAbajoL(){
        this-> fil+=1;
    }

    void irIzquierdaL(){
        this-> col-=1;
    }

    void irDerecha(){

        if(puedoDerecha())
            this-> col+=1;
    }

    bool puedoDerecha(){
        
        if(col < 8)
            return true;

        return false;
    }

    void irIzquierda(){

        if(puedoIzquierda()){
            this-> col-=1;
        }

    }

    bool puedoIzquierda(){

        if(col > 0){
            return true;
        }

        return false;
    }

    void irArriba(){
        
        if(puedoArriba()){
            this-> fil-=1;
        }

    }

    bool puedoArriba(){
        
        if(fil > 0){
            return true;
        }

        return false;

    }

    void irAbajo(){

        if(puedoAbajo()){
            this-> fil+=1;
        }

    }

    bool puedoAbajo(){

        if(fil < 8){
            return true;
        }

        return false;
    }

    void esconderCursor(){
        HANDLE hStdOut = NULL;
        CONSOLE_CURSOR_INFO curInfo;

        hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleCursorInfo(hStdOut, &curInfo);
        curInfo.bVisible = FALSE;
        SetConsoleCursorInfo(hStdOut, &curInfo);
    }

};