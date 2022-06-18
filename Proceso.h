#include <iostream>
#include "1Pila.hpp"
#include <conio.h>
#include <string>
#include <cstring>
#include "Regex.cpp"
#include "Calculadora.cpp"

using namespace std;
#pragma once
   
class Proceso{
    private:
        Pila<string> *infija = new Pila<string>();
        Pila<string> *postfija = new Pila<string>();
        Pila<string> *prefija = new Pila<string>();
        Regex *r = new Regex();

    public:

    Proceso(){
    }

    void evaluarPostfija();

    int pNumero();

    ~Proceso(){
        free(this);
    }

    Pila<string> *getInfija();
    void setInfija(Pila<string> *i);

    Pila<string> *getPostfija();
    void setPostfija(Pila<string> *post);

    Pila<string> *getPrefija();
    void setPrefija(Pila<string> *pre);

    bool recibirExpresion();

    void convertirPostfija();

    void convertirPrefija();

    bool esPrioritario(string &uno, string &dos);

    int pMultiplicacionDivision();

    int pSumaResta();

    int pExponenteRaiz();

    int pParentesis();

    int pNunmero();

    int pTrigonometricasLog();

    int operadores(const string &a);

    int prioridades(int operador);

    void reemplazaString(string& subject, const string& search, const string& replace);

    void reemplazoSignos(string& str);

    bool buscoSignos(string& str);


};