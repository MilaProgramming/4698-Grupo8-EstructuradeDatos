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

#include <iostream>
#include <graphics.h>
#include <windows.h>

int main()
{
	initwindow(700, 600, "Grupo 2", 300, 300);
	//setviewport(0,0,800,200,1);
	setbkcolor(COLOR(170,223,101));
	clearviewport();
	readimagefile("Grupo2.jpg",100, 20, 600, 580);
	getch();
	return 0;
}