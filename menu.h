#include <iostream>

using namespace std;

int menuEntrada(){
	int opc;
	cout<<"|----METODOS DE ORDENAMIENTO Y BUSQUEDA-------|"<<endl;
	cout<<"|                                             |"<<endl;
	cout<<"|1) Ingresar numeros.                         |"<<endl;
	/*cout<<"|2) Ordenamiento Intercambio                  |"<<endl;
	cout<<"|3) Ordenamiento Burbuja                      |"<<endl;
	cout<<"|4) Ordenamiento Quicksort                    |"<<endl;
	cout<<"|5) Ordenamiento Shellsort                    |"<<endl;
	cout<<"|6) Ordenamiento Radix                        |"<<endl;
	cout<<"|7) Buscar un numero.(Busqueda Secuencial)    |"<<endl;
	cout<<"|8) Buscar un numero.(Busqueda Binaria)       |"<<endl;*/
	cout<<"|2) Buscar un numero.(Busqueda Hash)          |"<<endl;
	cout<<"|0) Salir.                                    |"<<endl;
	cout<<"|                                             |"<<endl;
	cout<<"|---------------------------------------------|"<<endl;
	cin>>opc;
	
	return opc;
}

void mSmDespedida(){
		          
     system("cls"); 
	 cout<<"|/-------------------/|"<<endl;
	 cout<<"|/                   /|"<<endl;
	 cout<<"|/       *ADIOS*     /|"<<endl;
	 cout<<"|/                   /|"<<endl;
	 cout<<"|/-------------------/|"<<endl;
}

void mSmIncorrecto(){
	
	 cout<<"|#############################|"<<endl;
	 cout<<"|#   La opcion ingresada     #|"<<endl;
	 cout<<"|#      es incorrecta        #|"<<endl;
	 cout<<"|#############################|"<<endl;
	 system("pause");
}
