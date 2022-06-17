
#include "Nodo.h"

template<class T>
T Nodo<T>::getValor(void)
{
   return valor;
}

template<class T>
void Nodo<T>::setValor(T newValor)
{
   valor = newValor;
}
template<class T>
int Nodo<T>::getPrioridad(void)
{
   return prioridad;
}


template<class T>
void Nodo<T>::setPrioridad(int newPrioridad)
{
   prioridad = newPrioridad;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente(void)
{
   return siguiente;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo* newSiguiente)
{
   siguiente = newSiguiente;
}

template<class T>
Nodo<T>::Nodo(T _valor, Nodo* _siguiente)
{
   this->valor=_valor;
   this->siguiente=_siguiente;
   this->prioridad=0;
}


template<class T>
Nodo<T>::~Nodo()
{
   // TODO : implement
}