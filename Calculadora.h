#pragma once

class Calculadora{
	public:
		Pila<std::string>* prefijo(std::string*,int);
		Pila<std::string>* postfijo(std::string*,int);
		float calcular(Pila<std::string>*);
};