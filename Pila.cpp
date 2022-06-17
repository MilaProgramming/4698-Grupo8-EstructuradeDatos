#include "Pila.h"
template<class T>
Pila<T>::Pila(){
	this->primero=NULL;
}
template<class T>
int Pila<T>::tamanio(){
	int cont=0;
	Nodo<T>* nodo=primero;
	if(primero!=NULL){
		while(nodo!=NULL){
			cont++;
			nodo = nodo->getSiguiente();
		}
	}else{
		return 0;
	}
	return cont;
	
}
template<class T>
void Pila<T>::push(T valor){
	Nodo<T>* nuevo= new Nodo<T>(valor,primero);
		if(valor=="("||valor==")"){
			nuevo->setPrioridad(5);
		}else{
			if(valor=="sin"||valor=="cos"||valor=="tan"){
				nuevo->setPrioridad(4);
			}else{
				if(valor=="sqrt"||valor=="^"){
					nuevo->setPrioridad(3);
				}else{
					if(valor=="*"||valor=="/"){
					nuevo->setPrioridad(2);					
					}else{
						if(valor=="+"||valor=="-")
						nuevo->setPrioridad(1);
					}
				}
			}						
		}	
	primero = nuevo;
}
template<class T>
T Pila<T>::pop(){
	Nodo<T> *nodo=primero;
    T v;      
    if(!nodo){
    	primero=NULL;
    	return 0; 	
	}
    primero = nodo->getSiguiente();
    v = nodo->getValor();
    free(nodo);
    return v;	
}
template<class T>
Nodo<T>* Pila<T>::top(){
	return this->primero;
}
template<class T>
void Pila<T>::imprimir(){
	Nodo<T>* actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			std::cout<<actual->getValor(); 
			actual = actual->getSiguiente();
		}
	}else{
		std::cout <<" La Pila se encuentra vacia" << std::endl;
	}
}
template<class T>
std::string* Pila<T>::revertir(std::string *palabra,int i){
	Pila pila;
	std::string *aux=new std::string[50];
	for(int j=0;j<i;j++){
		pila.push(palabra[j]);
	}
	for(int j=0;j<i;j++){
		aux[j]=pila.pop();
	}
	return aux;
}





