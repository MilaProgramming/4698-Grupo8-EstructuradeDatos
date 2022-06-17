/************************************************************************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

* AUTHOR(es):  MATEO ROMAN, GENESIS CALAPAQUI , CAMILA RIVERA, ARIEL JARA.
* FECHA DE Inicio:  15 DE JUNIO DE 2022
* FECHA DE Entrega: 16 DE JUNIO DE 2022
* Version: 1
* ESTRUCTURA DE DATOS
* NRC: 4698
*************************************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h
template <class T>
class Nodo
{
public:
   T getValor(void);
   void setValor(T newValor);
   int getPrioridad(void);
   void setPrioridad(int newPrioridad);
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo* newSiguiente);
   Nodo(T _valor, Nodo* _siguiente);
   ~Nodo();

protected:
private:
   T valor;
   Nodo* siguiente;
   int prioridad;


};

#endif