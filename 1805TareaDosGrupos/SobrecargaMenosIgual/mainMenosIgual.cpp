/*
Autores: Shared Tinoco, Sebastian Torres, Camila Rivera, Mateo Román.
Fecha de creacion: 17/05/2022
Fecha de modificacion: 18/05/2022
Grupo 10 - Grupo 8
Github del grupo: https://github.com/Grupo8-4698-EstructuraDeDatos
*/


#include "MenosIgual.hpp"
#include <cstdio>

int main() {

	MenosIgual<int, int, 0, 0> enteros(5,2);
	MenosIgual<int, int, 0, 0> reales(2,5);
	
	enteros.imprimir();
	reales.imprimir();
    
    MenosIgual<int, int, 0, 0> nuevo;
    nuevo = enteros -= reales;

    nuevo.imprimir();

	return 0;
}