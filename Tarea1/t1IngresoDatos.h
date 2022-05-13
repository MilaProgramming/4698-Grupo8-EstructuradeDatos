#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

class Dato{
	private:
		 char *dato;	
		 int entero;	 
	public:
		Dato(){
			dato=new char[10];
		}
		void ingresarDatosEnteros(char *msj);
		void convertirEntero();
		int getEntero();
};

void Dato::ingresarDatosEnteros(char *msj){
	char c;
    int i=0;
    printf("%s ",msj);
    while((c=getch())!=13){
        if(c>='0'&& c<='9'){
            printf("%c",c);
            this->dato[i++]=c;
        }
    }
    dato[i]='\0';
    //puts(this->dato);
}
void Dato::convertirEntero(){
	this->entero=atoi(this->dato);
}
int Dato::getEntero()
{
	return this->entero;
}