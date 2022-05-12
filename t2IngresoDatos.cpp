#include "t2IngresoDatos.h"

//Constructor
IngresoDatos::IngresoDatos(){ 
}

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