#pragma once
#include "Nodo.h"
template <typename T>

class Pila{
private:
	Nodo<T>* primero= nullptr;
	//Nodo<T>* actual= nullptr;
	Nodo<T>* siguiente= nullptr;
	//Nodo<T>* pila = nullptr;

	int longitud;

public:
	Pila(){
		longitud=0;
	}
	~Pila(){
		free(this);
	}
	void apilar(T v) {
    	Nodo<T> *nuevo = new Nodo<T>(v);

    	if (primero == nullptr) {
        	primero = siguiente = nuevo;
    	}else if(primero == siguiente){    	
        	primero->setNodo(nuevo);
			siguiente=nuevo;
    	}else{
		siguiente -> setNodo(nuevo);	
    	siguiente = nuevo;
		}
	}

	void mostrar(){
    	Nodo<T> * tmp=this->primero;
    	while (tmp !=nullptr){
        std::cout << tmp->getValor()<<" ";
        tmp = tmp->getNodo();
    	}
	}	
	void desapilar() {
		if(primero == nullptr){
			cout<<"\n Pila Vacia"<<endl;
		}else if(primero ==siguiente){
			primero=siguiente=nullptr;
		}else{
    		Nodo<T>  *aux_borrar=siguiente->getNodo();
			siguiente->~Nodo();
			siguiente=aux_borrar;
        }
    	}
};	
	/*bool pilaVacia(){
    return (this->primero==NULL);
	}*/


