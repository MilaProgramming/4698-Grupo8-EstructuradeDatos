#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

char ingresoDatos(char);
char *ingresoDatosEntero(char *msj){
	char *dato=new char[10],c;
	int i=0;
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}

int main(int argc, char** argv) {
	char dato[10];
	int valor=0;
	strcpy(dato,ingresoDatosEntero("Ingrese el dato"));
	valor=atoi(dato);
	valor=valor*2;
	printf("\nresultado %d......",valor);
    
	return 0;
}	