#include "t3IngresoDatos.h"
#include "t3ConversionFloat.cpp"
#include "t3ConversionInt.cpp"

//Constructor
IngresoDatos::IngresoDatos(){ 
}

//Definicion de metodos

char* IngresoDatos::ingresoDatos(char *str){
    
    //Creo con memoria dinamica un array de caracteres
    char *dato=new char[50];
    //Creo un caracter, con el que voy a recibir el input
    char c;

    //Imprimo el mensaje de entrada, ingresado por parametro
    printf("%s ", str);

	return agregoChars(dato);
}

char* IngresoDatos::agregoChars(char *dato){
	//Creo un caracter, con el que voy a recibir el input
    char c;
	int j = 0; //Iterador para la verifiacion del unico punto
	int i;
	for(i=0; c != 13; i++){
		
		c=getch();

		if(c >= '0' && c <= '9' || c == 46){

			if(this -> converFloat.convertir(c)){
				if(j == 1){
					throw std::invalid_argument("Un decimal no puede tener mas de un solo punto");
				}else{
					printf("%c", c);
					dato[i]=c;
					++j;
					this -> det = 'f'; //flotante
				}
			}		else if(this -> converInt.convertir(c)){

						printf("%c", c);
						dato[i]=c;
						this -> det = 'i'; //entero
					}	else{
						printf("a chikitaaaaa");
						}

		} else if(c == 8){
			printf("%c", c);
			if(i != 0){
				dato[i]='\0';
				i--;
			}			
		}
	}

	dato[i]='\0';
	return dato;
}


