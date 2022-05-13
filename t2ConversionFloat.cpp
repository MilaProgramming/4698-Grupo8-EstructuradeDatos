#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "t2ConversionFloat.h"

//Constructor

ConversionFloat::ConversionFloat(){
}

//Definicion de metodos

bool ConversionFloat::convertir(char c){
    if (c == '\46'){
        return false;
    }else{
        return true;
    }
}

bool ConversionFloat::punto(char c){
    
    int i =0;
    if (c =='\46' && c != '\13'){
        return true;
    } else {
        return false;
    }

}

float ConversionFloat::numFloat(char* dato){
    return std::stof(dato);
}
