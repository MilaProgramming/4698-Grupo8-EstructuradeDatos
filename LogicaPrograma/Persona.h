#include <iostream>
#include <string>
#include "Celular.h"
#include "ListaDC.hpp"

using namespace std;

class Persona{
    private:
        string nombre;
        ListaDobleC<Celular> *lista = new ListaDobleC<Celular>();        
    public:
};