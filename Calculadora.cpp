#include <iostream>
#include "Calculadora.h"

using namespace std;
#pragma once
   
double Calculadora::suma(double a, double b){
    return a + b;
}

double Calculadora::resta(double a, double b){
    return a - b;
}

double Calculadora::multiplica(double a, double b){
    return a * b;
}

//!exepcion de 0
double Calculadora::division(double a, double b){
    return a / b;
}

double Calculadora::exponente(double a, double b){
    return pow(a,b);
}

//!exepcion de 0
double Calculadora::raiz(double a, double b){
    return pow(a,1/b);
}

//?Trigonometricas
//!en radianes

double Calculadora::sen(double a){
    return sin(a);
}

double Calculadora::cs(double a){
    return cos(a);
}

double Calculadora::tg(double a){
    return tan(a);
}

//!excepciones de 0

double Calculadora::csen(double a){
    return 1/sin(a);
}

double Calculadora::scs(double a){
    return 1/cos(a);
}

double Calculadora::ctg(double a){
    return 1/tan(a);
}

//?Hiperbolicas

double Calculadora::senh(double a){
    return sinh(a);
}

double Calculadora::csh(double a){
    return cosh(a);
}

double Calculadora::tgh(double a){
    return tanh(a);
}

//? Logaritmos

// //!manejo de excepcion > 0

double Calculadora::ln(double a){
    return log(a);
}

double Calculadora::ln10(double a){
    return log10(a);
}

// //!manejo excepcion log b = 0
double Calculadora::logc(double a, double b){
    return log(a)/log(b);
}