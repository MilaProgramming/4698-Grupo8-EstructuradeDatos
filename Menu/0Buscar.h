#pragma once

class Buscar{

     public:
        virtual int buscarPrimerNodo() = 0; //Método virtual puro o abstracto 
        virtual int buscarIndice(int) = 0;
};