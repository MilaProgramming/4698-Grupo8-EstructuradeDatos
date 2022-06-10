/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#pragma once

#include "1ListaDC.hpp"
#include "3Celular.cpp"
#include "3Persona.cpp"
#include "3Stock.cpp"
#include <fstream>
#include <string>


class Tienda{

    private: 
        Stock *stock = nullptr;
 
    public:    

        /* El constructor de la clase. */
        Tienda();
        /* Un destructor. */
        ~Tienda();
      /* Una función que comprueba si la lista está vacía. */
        bool estaVacio();
        /* Configuración del stock de la tienda. */
        void setStock( Stock *);
        /* Un getter para la variable privada `Stock *stock = nullptr;` */
        Stock* getStock();

        //Recomendaciones de compra        
        ListaDobleC<Celular*>* recomendarCelulares(Persona*); //Recomendar automaticamente a la persona un celular por presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMenor(double); //Devolver los celulares menores o iguales que el presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMayor(double); //Devolver celulares mayores o iguales que el presupuesto

        //Devuelven listas de objetos que cumplan con ciertos requisitos

        /* Una función que devuelve una lista de punteros a objetos de tipo Persona que tienen el mismo
        presupuesto. */
        ListaDobleC<Persona*>* personasPorPresupuestoIgual(double);
		/* Devolver una lista de punteros a objetos de tipo Persona que tienen el mismo nombre. */
        ListaDobleC<Persona*>* personasPorNombreIgual(string, string);
        /* Una función que devuelve una lista de punteros a objetos de tipo Persona que tienen el mismo
        nombre, apellido, presupuesto y edad. */
        ListaDobleC<Persona*>* personasIgual(string, string, double, char*);
       /* Una función que devuelve una lista de punteros a objetos de tipo Persona que tienen el mismo
       nombre, apellido, presupuesto y edad. */
        ListaDobleC<Persona*>* personasIgual(string nombre, string apellido, char* cedula);

       /* Una función que devuelve una lista de punteros a objetos de tipo Celular que tienen el mismo
       precio. */
        ListaDobleC<Celular*>* celularesPorPrecioIgual(double);
		/* Una función que devuelve una lista de punteros a objetos de tipo Celular que tienen la misma
        marca. */
        ListaDobleC<Celular*>* celularesPorMarcaIgual(string);

        //Funciones para el menu

      /* Agregar un teléfono celular a la tienda. */
        void agregarCelularTienda(Celular*);
       /* Una función que añade un móvil a la tienda. */
        void agregarCelularTiendaSinString(Celular*);

       /* Eliminar un celular de la tienda. */
        void eliminarCelularTienda(Celular*);
       /* Búsqueda de un celular por nombre. */
        void buscarPorNombreCelular(string);
        /* Buscando un celular por precio. */
        void buscarPorPrecioCelular(double);

       /* Añadir una persona a la tienda. */
        void agregarPersonaTienda(Persona*);
       /* Una función que agrega una persona a la tienda. */
        void agregarPersonaSinString(Persona*);
        /* Eliminación de una persona de la tienda. */
        void eliminarPersonaTienda(Persona*);
        /* Búsqueda de una persona por su nombre. */
        void buscarPorNombrePersona(string, string);
        /* Búsqueda de una persona por su presupuesto. */
        void buscarPorPresupuestoPersona(double);

        /* Una función que se utiliza para comprar un teléfono celular. */
        void comprarCelular(string, string, string, double, char*);
       /* Una función que se utiliza para comprar un teléfono celular. */
       void comprarCelular(string, string, string, double,  int, char*);
        /* Una función que se utiliza para comprar un teléfono celular. */
        void comprarCelular(string, string, string, char*);
        /* Una función que se utiliza para comprar un teléfono celular. */
        void comprarCelular(string, string, string, int, char*);
        /* Una función que se utiliza para comprar un teléfono celular. */
        void comprarCelular(Persona*, Celular*);
       /* Una función que se utiliza para comprar un teléfono celular. */
        void comprarCelular(Persona*, Celular*, int);

        /* Una función que se utiliza para recomendar un teléfono celular a una persona. */
        bool recomendarAutomatico(string, string, double, char*);
       /* Una función que devuelve una lista de punteros a objetos de tipo Celular que tienen un precio
       menor o igual al presupuesto. */
        bool recomendarMenores(double);
        /* Una función que devuelve una lista de punteros a objetos de tipo Celular que tienen un
        precio mayor o igual al presupuesto. */
        bool recomendarMayores(double);
        /* Una función que se utiliza para configurar los correos electrónicos de las personas que
        compraron un teléfono celular. */
        void establecerCorreos();

        //Validaciones
       /* Una función que comprueba si la cédula es correcta. */
        bool cedulaCorrecta(char*);
       /* Comprobando si el stock es correcto. */
        bool stockCorrecto(int);
       /* Comprobar si el presupuesto es correcto. */
        bool presupuestoCorrecto(double);

        //Leer txts
       /* Importando un archivo con el nombre de la cadena. */
        void importarCelulares(string);
       /* Importando un archivo con el nombre de la cadena. */
        void importarPersonas(string);

        /* Exportando los teléfonos móviles a un archivo. */
        void exportarCelulares(string);
        /* Exportando las personas a un archivo. */
        void exportarPersonas(string);
        /* Exportación de un informe a un archivo. */
        void exportarInforme(string);
  
};
