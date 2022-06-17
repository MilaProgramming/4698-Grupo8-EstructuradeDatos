#pragma once
#include"Pila.cpp"
class MenuOpciones{
	public:
		int menu(const char*[] ,int);
		void menu_inicial(Pila<char>*);		
		std::string *ingresoCaracteres(int*);
		bool validarExpresion(std::string*,int*);
};

