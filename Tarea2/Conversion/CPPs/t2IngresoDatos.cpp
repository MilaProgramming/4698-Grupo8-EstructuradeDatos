#include "Header/t2IngresoDatos.h"

//Constructor
IngresoDatos::IngresoDatos(){ 
}

//Definicion de metodos

char* IngresoDatos::ingresoDatos(string str){
    
    //Creo con memoria dinamica un array de caracteres
    char *dato=new char[20];
    //Creo un caracter, con el que voy a recibir el input
    char c;

    //Imprimo el mensaje de entrada, ingresado por parametro
    printf("%s ", str);

	int i=0;
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';

	return dato;
}

char* IngresoDatos::agregoChars(char *dato){
	//Creo un caracter, con el que voy a recibir el input
    char c;
	int pos; //Posicion final del arreglo
	int j = 0; //Iterador para la verifiacion del unico punto

	for(int i=0;(c=getch())!='\13'; i++){
		if(c >= '\0' && c <= '\9' && c == '\46'){
			if(this -> converFloat.convertir(c) && j == 0){

				printf("%c", c);
				dato[i]=c;
				pos++;
				j = 1;
				this -> det = 'f'; //flotante

			}	else if(j == 1){

					throw std::invalid_argument("Un decimal no puede tener mas de un solo punto");

				}	else if(this -> converInt.convertir(c)){

						printf("%c", c);
						dato[i]=c;
						pos++;
						this -> det = 'i'; //entero
					}	else{
						printf("a chikita");
						}

		}else if(c == '\8'){
			dato[i-1]='\0';
			--i;
			--pos;
		}
	}

	dato[pos]='\0';
	return dato;
}


