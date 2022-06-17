#include"windows.h"
#include"Menu.h"
#include"Calculadora.cpp"
const float pi = std::acos(-1);
class Menu:public MenuOpciones{
	
	public:
		
		int menu(const char* Menu[] ,int opcion){	
			while(true)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);			
				std::cout << "\n\n\tMENU \n\tPILAS\n";			
				for (int i = 0; i < 3; ++i)
				{
					if (i == opcion)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
						std::cout << Menu[i] <<std:: endl;
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						std::cout << Menu[i] << std::endl;
					}
				}			
				while(true)
				{					
					if (GetAsyncKeyState(VK_UP) != 0)
					{
						opcion -= 1;
						if (opcion == -1)
						{
							opcion = 2;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)
					{
						opcion += 1;
						if (opcion == 3)
						{
							opcion = 0;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						return opcion;
					}							
				}
			Sleep(150);
			}
		}
		
		void menu_inicial(Pila<std::string>* pila){
			const char *Menu[3] = {"\tInsertar", "\tConvertir","\tSalir"};
			std::string *palabra= new std::string[50];
			palabra=NULL;
			Calculadora calculadora;
			int *t=new int[10];
			int op,i;
			op=menu(Menu,-1);
			system("cls");
			while(op!=2){
				switch (op)
				{
					case 0:
					{
						std::cin.ignore();	
						std::cout<<"Ingrese la expresion: \n";
						palabra=ingresoCaracteres(t);
						if(!validarExpresion(palabra,t)){
							std::cout<<"\nExpresion invalida\n";
							palabra=NULL;
						}				
						std::cout<<std::endl;
						system("pause");
					}
					break;
					case 1:
					{
						std::cin.ignore();
						if(palabra){
							std::cout<<"Expresion prefija: ";
							calculadora.prefijo(palabra,*t)->imprimir();
							std::cout<<"\nExpresion postfija: ";
							calculadora.postfijo(palabra,*t)->imprimir();
							std::cout<<"\nResultado: "<<calculadora.calcular(calculadora.postfijo(palabra,*t))<<"\n";
							std::cout<<std::endl;	
							system("pause");	
						}else{
							std::cout<<"No se ha ingresado ninguna expresion\n";
							system("pause");	
						}
						
					break;	
					}
					case 2:
					{
						std::cout << "\n\n\n\nSalio con exito";
					break;	
					}												
				}
				system("cls");				
				op=menu(Menu,-1);
				system("cls");						
			}	
		}
		
		
		std::string *ingresoCaracteres(int *t){			
			std::string *dato=new std::string[50],expresion="";
			char c=0;
			bool aux=false,valido=false;
			int i=0;
			system("cls");
			do{
				if(c==13)
				break;
				while(c!=13){
					std::cout<<c;	
					if(c==0){				
					c=getch();
					std::cout<<c;	
					}
					try{			
						if(c>=97&& c<=122){									
							do{	
								std::string tmp;			
								tmp.push_back(c);
								expresion+=tmp;								
								c=getch();
								std::cout<<c;
							}while(c>=97&& c<=122);							
			    			if(expresion=="sin"||expresion=="cos"||expresion=="tan"||expresion=="sqrt"||expresion=="pi"){
			    				if(expresion=="pi"){
			    					expresion=std::to_string(pi);
								}
			    				dato[i++]=expresion;
								aux=true;
								expresion="";
							}else{
								std::cout<<"Expresion ingresada invalida\n";
								system("pause");
								expresion="";
								c=0;
								
							}							
						}else{
							if(c>='0'&& c<='9'){
								do{
									std::string tmp1;			
									tmp1.push_back(c);	
									expresion+=tmp1;	
									c=getch();
									std::cout<<c;
								}while(c>='0'&& c<='9');	
								dato[i++]=expresion;
								aux=true;
								expresion="";
							}else{
								if(c>=40&& c<=43||c==45||c==47||c==94){
									std::string tmp2;			
									tmp2.push_back(c);	
									dato[i++]=tmp2;
									aux=true;
									c=0;
								}else{
									if(c==8||c==127){
									if(i<=0){
									i=0;
									std::cout<<"Dato vacio\n";
									break;
									}else{
									dato[--i]=' ';			
									c=0;	
									}						        																			
									}else{
										if(c!=13){
											c=0;
											throw "\nIngrese un caracter valido\n";	
										}
																				
									}
									
									if(i==0){aux=false;}																											
								}
							}															
						}
												
						system("cls");
						for(int j=0;j<i;j++){				
							std::cout<<dato[j];
						}
					
					}catch(const char * s){
						printf("\n%s",s);
					}
				}
				if(aux==false){std::cout<<"\nERROR: Ingrese un valor\n";}
			}while(aux==false);
			*t=i;
			dato[i]='\0';
			return dato;		
		}
		
		bool validarExpresion(std::string* expresion,int* i){
			bool valido=false;
			int izq=0,der=0;
			for(int j=0;j<*i;j++){
				if(expresion[j]=="("){
					izq++;
				}else{
					if(expresion[j]==")"){
						der++;
					}
				}
			}
			if(izq==der){
				valido=true;
			}
			if(expresion[0]=="*"||expresion[0]=="+"||expresion[0]=="-"||expresion[0]=="/"||expresion[0]=="^"||expresion[0]==")"){
				valido=false;
			}
			if(expresion[*i-1]=="*"||expresion[*i-1]=="+"||expresion[*i-1]=="-"||expresion[*i-1]=="/"||expresion[*i-1]=="^"||expresion[*i-1]=="("){
				valido=false;
			}
			if(expresion[*i-1]=="sin"||expresion[*i-1]=="cos"||expresion[*i-1]=="tan"||expresion[*i-1]=="sqrt"){
				valido=false;
			}
			return valido;
		}	
};