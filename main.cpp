#include <iostream>
#include "funciones.h"
#include "menu.h"
#include "hash.h"

using namespace std;

int main(int argc, char** argv) {
	int * arreglo=NULL;
	int tam=0;
	int opc;

do{
	system("cls");
	
	opc=menuEntrada();
	switch(opc){
		case 1:{
			arreglo=(int*)realloc(arreglo,(tam+1)*sizeof(int));
			if(arreglo!=NULL)
			{
				cout<<"Ingrese un numero: ";
				cin>>arreglo[tam];
				
				tam++; 
				imprimir(arreglo,tam);
			}
			else
				cout<<"\nERROR. No se pudo reservar memoria. ";
			 
			system("pause");				
			break;
		}
		/*¡case 2:{
			//intercambio (descendente)
			intercambio(arreglo, tam);
			cout<<"Ascendente: ";
			imprimirAscendente(arreglo, tam);
			cout<<endl;
			
			cout<<"Descendente: ";
			imprimirDescendente(arreglo, tam-1);
			cout<<endl;  
			system("pause");
			break;
		}
		case 3:{
			//burbuja (ascendente)
			cout<<"Metodo burbuja"<<endl;
			burbuja(arreglo, tam);
			cout<<"Ascendente: ";
			imprimirAscendente(arreglo, tam);
			cout<<endl;
			
			cout<<"Descendente: ";
			imprimirDescendente(arreglo, tam-1);
			cout<<endl;
			system("pause");
			
			break;
		}
		case 4:{
			//quick (ascendente)
			quicksort(arreglo,0,tam-1);
			cout<<"Ascendente: ";
			imprimirAscendente(arreglo, tam);
			cout<<endl;
			
			cout<<"Descendente: ";
			imprimirDescendente(arreglo, tam-1);
			cout<<endl;
			system("pause");

			break;
		}
		
		case 5:{
			//shell (ascendente)
			cout<<"Metodo shell"<<endl;
			shellSort(arreglo, tam);
			cout<<"Ascendente: ";
			imprimirAscendente(arreglo, tam);
			cout<<endl;
			
			cout<<"Descendente: ";
			imprimirDescendente(arreglo, tam-1);
			cout<<endl;
			system("pause");

			break;
		}
		
		case 6:{
			//radix (ascendente)
			cout<<"Metodo radixsort"<<endl;
			radixsort(arreglo, tam);
			cout<<"Ascendente: ";
			imprimirAscendente(arreglo, tam);
			cout<<endl;
			
			cout<<"Descendente: ";
			imprimirDescendente(arreglo, tam-1);
			cout<<endl;
			system("pause");

			break;
		}
		
		case 7:{
			int sec;
			int num;
			cout<<"ingrese un numero a buscar"<<endl;
			cin>>num;
			sec=secuencial(arreglo,tam,num);
			if(sec==-1){
				cout<<"Elemento no encontrado"<<endl;
			}else{
				cout<<"Elemento encontrado en la posicion: "<<sec<<endl;
			}
			system("pause");
		
			break;
		}
		
		case 8:
		{
			int num;
			cout<<"ingrese un numero a buscar"<<endl;
			cin>>num;
			binaria(arreglo,num,0,tam);
			system("pause");
		
			break;
		}*/
		
		case 2:{
			
			int n = sizeof(arreglo)/sizeof(arreglo[0]);

			Hash h(n); 
			for (int i = 0; i < n; i++)
				h.insertar(arreglo[i]);
						
			h.mostrarHash();
			
			system("pause");
		
			break;
		}
		
		case 3:{
			
			int n = sizeof(arreglo)/sizeof(arreglo[0]);

			Hash h(n); 
			for (int i = 0; i < n; i++)
				h.insertar(arreglo[i]);
						
			h.mostrarHash();
			
			system("pause");
		
			break;
		}
		
		case 0:{
			mSmDespedida();
			break;
		}
		
		default:{
		    mSmIncorrecto();
			break;
		}	
		
	}

}while(opc!=0);
	return 0;
}
