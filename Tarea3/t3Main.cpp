/*ESPE
*Enunciado del problema:
*   Realizar una funcion que reciba un string y retorne un entero o flotante segun corresponda
* y que contenga a todas las funciones de las demás.
*Autor 
*   Camila Rivera
*   Mateo Roman
*Fecha de creacion
*   11-05-2022
*Fecha de modificacion
*    - 05 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#include "t3IngresoDatos.cpp"

int main(){

	int n, opcion;

    do
    {
        printf( "\n-----Bienvenido escoja una opcion-----");
		printf( "\n   1. Transformar el valor", 163 );
        printf( "\n   2. Salir." );
        printf( "\n\n   Introduzca opci%cn (1-2): ", 162 );

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:     	
				IngresoDatos *a = new IngresoDatos();
				char *dato=new char[50];
				dato = a -> ingresoDatos("Ingrese sus numeritos: ");
				
				if((a -> getDet()) == '\0'){
					printf("\n Su numero es %i, y es un entero", a -> devolverInt(dato));
				}else if((a -> getDet()) == 'f'){
					printf("\n Su numero es %f, y es un flotante", a -> devolverFloat(dato));
				}else{
					printf("\n No estoy funcionando");
				}
                    break;
         }

         /* Fin del anidamiento */

    } while ( opcion != 2 );


    return 0;
}