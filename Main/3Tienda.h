#pragma once
#include "1ListaDC.hpp"
#include "3Celular.cpp"
#include "3Persona.cpp"
#include "3Stock.cpp"

class Tienda{

    private: 
        Stock *stock = nullptr;
 
    public:    

        Tienda();
        ~Tienda();
        bool estaVacio();

        void setStock( Stock *);
        Stock* getStock();

        //Recomendaciones de compra        
        ListaDobleC<Celular*>* recomendarCelulares(Persona*); //Recomendar automaticamente a la persona un celular por presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMenor(double); //Devolver los celulares menores o iguales que el presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMayor(double); //Devolver celulares mayores o iguales que el presupuesto

        //Devuelven listas de objetos que cumplan con ciertos requisitos
        ListaDobleC<Persona*>* personasPorPresupuestoIgual(double);
		ListaDobleC<Persona*>* personasPorNombreIgual(string, string);

        ListaDobleC<Celular*>* celularesPorPrecioIgual(double);
		ListaDobleC<Celular*>* celularesPorMarcaIgual(string);

        //Funciones para el menu

        void agregarCelularTienda(Celular*);
        void eliminarCelularTienda(Celular*);
        void buscarPorNombreCelular(string);
        void buscarPorPrecioCelular(double);

        void agregarPersonaTienda(Persona*);
        void eliminarPersonaTienda(Persona*);
        void buscarPorNombrePersona(string, string);
        void buscarPorPresupuestoPersona(double);

        void comprarCelular(string, string, string);
        bool recomendarAutomatico(string, string);
        bool recomendarMenores(double);
        bool recomendarMayores(double);



    
};
