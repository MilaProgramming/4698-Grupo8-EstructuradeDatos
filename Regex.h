#include <iostream>
#include <regex>
#include "1Pila.hpp"
using namespace std;
#pragma once
   
class Regex{
    private:
        int longitud=0;
    public:
        Regex(){

        }

        ~Regex(){
            free(this);
        }

        bool esUnNumero(const string &a);

        Pila<string>* fragmento(const string &a);
};