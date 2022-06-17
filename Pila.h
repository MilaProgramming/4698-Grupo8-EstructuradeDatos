#pragma once
#include"Nodo.cpp"
template<class T>
class Pila{
	private:
		Nodo<T>* primero;
		bool PilaVacia(){
			return (this->primero==NULL);
		}
	public:
		Pila();
		void push(T);
		T pop();
		Nodo<T>* top();
		std::string* revertir(std::string*,int);		
		int tamanio();		
		void imprimir();
};
