#include<cmath>
#include<iostream>
#include<conio.h>
#include "Menu.cpp"
int main(){
	Pila<std::string> *pila=new Pila<std::string>();
	Menu menu;
	menu.menu_inicial(pila);
	return 0;
}
