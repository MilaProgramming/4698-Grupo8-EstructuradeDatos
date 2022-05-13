#include "t2IngresoDatos.h"
#include "t2ConversionFloat.cpp"
#include "t2ConversionInt.cpp"

//Constructor
IngresoDatos::IngresoDatos(){ 
}

//Definicion de metodos

char* IngresoDatos::ingresoDatos(char *str){
    
    //Creo con memoria dinamica un array de caracteres
    char *dato=new char[20];
    //Creo un caracter, con el que voy a recibir el input
    char c;

    //Imprimo el mensaje de entrada, ingresado por parametro
    printf("%s ", str);

	return agregoChars(dato);
}

char* IngresoDatos::agregoChars(char *dato){
	//Creo un caracter, con el que voy a recibir el input
    char c;
	int pos=0; //Posicion final del arreglo
	int j = 0; //Iterador para la verifiacion del unico punto

	for(int i=0; c != 13; i++){
		
		c=getch();

		if(c >= '0' && c <= '9' || c == 46){

			if(this -> converFloat.convertir(c)){
				if(j == 1){
					throw std::invalid_argument("Un decimal no puede tener mas de un solo punto");
				}else{
					printf("%c", c);
					dato[i]=c;
					pos++;
					++j;
					this -> det = 'f'; //flotante
				}
			}		else if(this -> converInt.convertir(c)){

						printf("%c", c);
						dato[i]=c;
						pos++;
						this -> det = 'i'; //entero
					}	else{
						printf("a chikitaaaaa");
						}

		} else if(c == 8){
			
			if(i != 0){
				i--;
				dato[i]='\0';
				--pos;
			}			
		}
	}

	dato[pos]='\0';
	return dato;
}

int main(){
	IngresoDatos *a = new IngresoDatos();

	a -> ingresoDatos("Ingrese sus numeritos: ");

	return 0;
}

