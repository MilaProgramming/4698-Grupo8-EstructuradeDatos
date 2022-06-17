#include"Calculadora.h"

Pila<std::string>* Calculadora::prefijo(std::string* palabra,int i){
	Pila<std::string> *pila;
	palabra=pila->revertir(palabra,i);
	Pila<std::string> *prefija=new Pila<std::string>();
	Pila<std::string> *operadores=new Pila<std::string>();
	for(int j=0;j<i;j++){
		if(palabra[j]==")"){
			operadores->push(palabra[j]);
		}else{
			if(palabra[j]=="("){
				std::string aux;
				do{
					aux=operadores->pop();
					prefija->push(aux);	
					if(aux==")")
					prefija->pop();				
				}while(aux!=")");
			}else{
				if(palabra[j]=="sin"||palabra[j]=="cos"||palabra[j]=="tan")	{
					if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==4){
						prefija->push(operadores->pop());
						operadores->push(palabra[j]);
					}else{
						prefija->push(palabra[j]);
					}
				}else{
					if(palabra[j]=="sqrt"||palabra[j]=="^"){
						if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==3){
							prefija->push(operadores->pop());
							operadores->push(palabra[j]);			
						}else{
							if(operadores->top()!=NULL&&operadores->top()->getPrioridad()>3){
								std::string aux1="";
								while(aux1!=")"&&operadores->top()!=NULL){
									aux1=operadores->pop();
									prefija->push(aux1);	
									if(aux1==")"){
										prefija->pop();
										operadores->push(")");
									}													
								
								}	
								operadores->push(palabra[j]);
							}else{
								operadores->push(palabra[j]);
							}
						}	
					}else{
						if(palabra[j]=="*"||palabra[j]=="/"){
						if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==2){
							prefija->push(operadores->pop());
							operadores->push(palabra[j]);		
						}else{
							if(operadores->top()!=NULL&&operadores->top()->getPrioridad()>2){
								std::string aux3="";
								while(aux3!=")"&&operadores->top()!=NULL){
									aux3=operadores->pop();
									prefija->push(aux3);	
									if(aux3==")"){
										prefija->pop();
										operadores->push(")");
									}													
								}
								operadores->push(palabra[j]);	
							}else{
								operadores->push(palabra[j]);
							}
						}
						}else{
							if(palabra[j]=="+"||palabra[j]=="-"){
							if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==1){
								prefija->push(operadores->pop());
								operadores->push(palabra[j]);			
							}else{
								if(operadores->top()!=NULL&&operadores->top()->getPrioridad()>1){
								std::string aux4="";								
								while(aux4!=")"&&operadores->top()!=NULL){									
									aux4=operadores->pop();									
									prefija->push(aux4);
									if(aux4==")"){
										prefija->pop();
										operadores->push(")");
									}													
								}
								operadores->push(palabra[j]);	
							}else{
								operadores->push(palabra[j]);
							}
								
							}
							}else{
								prefija->push(palabra[j]);
								
							}
						}				
				}
			}			
		}
		}
	}
	while(operadores->top()){		
		prefija->push(operadores->pop());		
	}
	return prefija;	
}


Pila<std::string>* Calculadora::postfijo(std::string* palabra,int i){
	Pila<std::string> *postfija=new Pila<std::string>();
	Pila<std::string> *operadores=new Pila<std::string>();
	for(int j=0;j<i;j++){
		if(palabra[j]=="("){
			operadores->push(palabra[j]);
		}else{
			if(palabra[j]==")"){
				std::string aux;
				do{
					aux=operadores->pop();
					postfija->push(aux);	
					if(aux=="(")
					postfija->pop();				
				}while(aux!="(");
			}else{
				if(palabra[j]=="sin"||palabra[j]=="cos"||palabra[j]=="tan")	{
					if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==4){
						postfija->push(operadores->pop());
						operadores->push(palabra[j]);
					}else{
						operadores->push(palabra[j]);
					}
				}else{
					if(palabra[j]=="sqrt"||palabra[j]=="^"){
						if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==3){
							postfija->push(operadores->pop());
							operadores->push(palabra[j]);			
						}else{
							if(operadores->top()!=NULL&&operadores->top()->getPrioridad()>3){
								std::string aux1="";
								while(aux1!="("&&operadores->top()!=NULL){
									aux1=operadores->pop();
									postfija->push(aux1);	
									if(aux1=="("){
										postfija->pop();
										operadores->push("(");
									}													
								
								}	
								operadores->push(palabra[j]);
							}else{
								operadores->push(palabra[j]);
							}
						}	
					}else{
						if(palabra[j]=="*"||palabra[j]=="/"){
						if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==2){
							postfija->push(operadores->pop());
							operadores->push(palabra[j]);		
						}else{
							if(operadores->top()!=NULL&&operadores->top()->getPrioridad()>2){
								std::string aux3="";
								while(aux3!="("&&operadores->top()!=NULL){
									aux3=operadores->pop();
									postfija->push(aux3);	
									if(aux3=="("){
										postfija->pop();
										operadores->push("(");
									}													
								}
								operadores->push(palabra[j]);	
							}else{
								operadores->push(palabra[j]);
							}
						}
						}else{
							if(palabra[j]=="+"||palabra[j]=="-"){
							if(operadores->top()!=NULL&&operadores->top()->getPrioridad()==1){
								postfija->push(operadores->pop());
								operadores->push(palabra[j]);			
							}else{
								if(operadores->top()!=NULL&&operadores->top()->getPrioridad()>1){
								std::string aux4="";								
								while(aux4!="("&&operadores->top()!=NULL){									
									aux4=operadores->pop();									
									postfija->push(aux4);
									if(aux4=="("){
										postfija->pop();
										operadores->push("(");
									}													
								}
								operadores->push(palabra[j]);	
								}else{
									operadores->push(palabra[j]);
									}								
								}
							}else{
								postfija->push(palabra[j]);								
							}
						}				
					}
				}			
			}
		}
	}
	while(operadores->top()){		
		postfija->push(operadores->pop());		
	}
	Pila<std::string> *rev=new Pila<std::string>();
	while(postfija->top()){	
		rev->push(postfija->pop());	
	}
	return rev;
}

float Calculadora::calcular(Pila<std::string>* expresion){
	float resultado=0;
	Pila<std::string> *numero= new Pila<std::string>();
	while(expresion->top()){
		if(expresion->top()->getValor()=="sin"){
			resultado=sin(std::stof(numero->pop()));
			numero->push(std::to_string(resultado));
			expresion->pop();
		}else{
			if(expresion->top()->getValor()=="cos"){
			resultado=cos(std::stof(numero->pop()));
			numero->push(std::to_string(resultado));
			expresion->pop();
			}else{
				if(expresion->top()->getValor()=="tan"){
				resultado=tan(std::stof(numero->pop()));
				numero->push(std::to_string(resultado));
				expresion->pop();
				}else{
					if(expresion->top()->getValor()=="sqrt"){
					resultado=sqrt(std::stof(numero->pop()));
					numero->push(std::to_string(resultado));
					expresion->pop();
					}else{
						if(expresion->top()->getValor()=="^"){
						int exp = std::stof(numero->pop());
						resultado=pow(std::stof(numero->pop()),exp);
						numero->push(std::to_string(resultado));
						expresion->pop();
						}else{
							if(expresion->top()->getValor()=="*"){
								resultado=std::stof(numero->pop())*std::stof(numero->pop());
								numero->push(std::to_string(resultado));
								expresion->pop();
							}else{
								if(expresion->top()->getValor()=="/"){
								float denominador=std::stof(numero->pop());
								if(denominador!=0){
									resultado=std::stof(numero->pop())/denominador;
									numero->push(std::to_string(resultado));
									expresion->pop();	
								}else{
									std::cout<<"\nNo se puede calcular la expresion ya que la division para 0 no esta definida.\n";
									numero->push("0");
									break;
								}								
								}else{
									if(expresion->top()->getValor()=="+"){
									resultado=std::stof(numero->pop())+std::stof(numero->pop());
									numero->push(std::to_string(resultado));
									expresion->pop();
									}else{
										if(expresion->top()->getValor()=="-"){
										float sustraendo=std::stof(numero->pop());
										resultado=std::stof(numero->pop())-sustraendo;
										numero->push(std::to_string(resultado));
										expresion->pop();
										}else{
											numero->push(expresion->pop());
										}
									}
								}
							}
						}
					}
				}
			}
		}
				
	}
	return std::stof(numero->pop());
}