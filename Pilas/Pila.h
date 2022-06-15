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
			
    	}else {    	
			nuevo->setNodo(siguiente);
			siguiente=nuevo;
		}
	}

	void mostrar(){
    	Nodo<T> * tmp=this->siguiente;
    	while (tmp !=nullptr){
        std::cout << tmp->getValor()<<" ";
        tmp = tmp->getNodo();
    	}
	}	
	void desapilar() {
		Nodo<T> * tmp;
		if(primero == nullptr){
			cout<<"\n Pila Vacia"<<endl;
		}else if(primero ==siguiente){
			Nodo<T>  *aux_borrar=siguiente->getNodo();
			cout<<"\n Desapilando: "<<aux_borrar->getValor()<<endl;
			primero = siguiente=nullptr;
			delete aux_borrar;
		}else{
    		Nodo<T>  *aux_borrar=siguiente;
			cout<<"\n Desapilando: "<<aux_borrar->getValor()<<endl;
			siguiente=aux_borrar->getNodo();
			delete aux_borrar;
        }
    	}
};	
	/*bool pilaVacia(){
    return (this->primero==NULL);
	}*/


