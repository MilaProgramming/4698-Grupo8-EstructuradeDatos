
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