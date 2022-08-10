#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;
#pragma once

class CuadradoMagico{

    private:

        int** cuadrado; 
        fstream archivo;
        int n; //n

        //! Variables Metodo 2
        int inicio;
        int auxiliar;
        int numeroMagico;
        int* numeros;
        //!

        //!Variables Metodo 3
        int f, c;
        int** matriz;
        int* num;
        //!
    
        //! Metodos Generales
        void encerar(){

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    *(*(cuadrado + i) + j) = 0;
                }
            }

        }

        void imprimir(){

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << *(*(cuadrado + i) + j) << " ";
                }
                cout <<endl;
            }
            cout <<endl;
        }

        void exportarTxt(int metodo){

            archivo.open("cuadradoMagico.txt", fstream::app);
            if(archivo.is_open()){

                archivo << "Metodo " << metodo <<endl;

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        archivo<< *(*(cuadrado+i)+j) << " ";
                    }

                    archivo<<endl;
                }
                archivo<<endl;

            }else{
                cout<< "\n Ocurrio un error con el txt" <<endl;
            }

            archivo.close();
        }
        //! 

        //!Metodo I
        bool estaOcupado(int i, int j){
            return *(*(cuadrado + i) + j) != 0;
        }

        void corregirIndices(int *i, int *j){
            
            if(*i < 0 && *j >= n){
                *i = 0;
                *j = n-2;
        

            }else if(*i < 0){
                *i = n-1;
     

            }else if(*j >= n){
                *j = 0;
     
            }

        }

        //!

        //!Metodo II

        void generarVector(){
            for(int i=0;i<pow(n,2);i++){
                *(numeros+i)=inicio+i;
            }	
	    }

        int* obtenerPares(){
            int* pares=new int[4];
            int aux=0;
            for(int i=0;i<pow(n,2);i++){
                if(*(numeros+i)%2==0){
                    *(pares+aux)=*(numeros+i);	
                    aux++;
                }
            }
            return pares;	
        }

        int* obtenerImpares(){
         
            int* impares = new int[4];
            int aux = 0;
            for(int i=0;i<9;i++){
                if(*(numeros+i)%2 != 0){
                  
                    *(impares+aux)=*(numeros+i);	
                    aux++;			
                }
            }
   
            return impares;
        }

        void obtenerNumeroMagico(){
            for(int i=0;i<pow(n,2);i++){
                numeroMagico+=*(numeros+i);						
            }
            numeroMagico=numeroMagico/n;
	    }

        void encerarNumeros(){
            for(int i=0;i<pow(n,2);i++){
                *(numeros+i)=0;
            }	
        }
        //!

        //!Metodo II

        void generarVect(){

            for(int i=0;i<11;i++){
                if(i==3||i==7){
                    num[i]=0;
                }else{
                    num[i]=inicio++;
                }
		    }	
        }

        void imprimirMatriz(){		
            for (int i = 0; i < f; i++) {
                for (int j =0; j<c; j++) {
                    cout<<matriz[i][j]<<" ";	
                }
                cout<<endl;
            }	
	    }

        void encerarMatriz(){
            for (int i=0;i<f;i++){
                for(int j=0;j<c;j++){
                    matriz[i][j]=0;		
                }
            }	
	    }

        void llenarMatriz(){
            int n=0,cont=0,cont1=1,cont2=0,fila,colum;
            for (int i = 0; i < f; i++) {
                n++;
                if(n>2){
                    if(n%2!=0){
                        for (int j = 0; j<n; j++) {
                            matriz[cont1-1][n-cont1]=num[cont2];				    	
                            cont2++;	
                            cont1++;				    	
                        }
                    }
                }
                cont1=1;
            }
            cont1=1;
            n=f;
            fila=0;
            colum=f;
            for (int i = 0; i < f-1; i++) {
                n--;
                if(n==3){
                    for (int j = 0; j<n; j++) {
                        matriz[fila+cont1][colum-cont1]=num[cont2];
                        cont2++;
                        cont1++;   	
                    }
                }
                fila++;
                colum=f;
                cont1=1;	
            }
            matriz[1][2]=matriz[4][2];
            matriz[3][2]=matriz[0][2];
            matriz[2][1]=matriz[2][4];
            matriz[2][3]=matriz[2][0];	
            
        }
        //!

    public:

    CuadradoMagico(int num): cuadrado(new int*[3]), n(3), inicio(num), auxiliar(num), numeroMagico(0), numeros(new int[9]), f(5), c(5), matriz(new int*[5]), num(new int[11]){

        for(int i = 0; i < 3; i++)
                *(cuadrado + i) = new int[3];

        for(int i = 0; i < 5; i++)
                *(matriz + i) = new int[5];

        archivo.open("cuadradoMagico.txt",fstream::out);
        archivo.close();
    }
    
    ~CuadradoMagico(){
        delete [] cuadrado;
    }

    void metodoI(){

        encerar();
    
        int i{0}, j{0};
        int numeros{1};
        bool condicional{false};
       
       while(numeros <= 9){

            if(numeros == 1){
                i = n/2;
                j = n-1; 
                *(*(cuadrado + i) + j) = numeros;
                numeros++;
                condicional = true;

            }else{
                
                if(condicional){
                    --i;
                    ++j;

                    condicional = false;
                }

                corregirIndices(&i,&j);


                if(!(estaOcupado(i,j))){
                    *(*(cuadrado + i) + j) = numeros;
                    numeros++;
                    condicional = true;

                }else{
                    ++i;
                    j = j-2;

                }

            }
        }

        imprimir();
        exportarTxt(1);

    }

    void metodoII(){

        encerar();
        encerarNumeros();
        generarVector();
        obtenerNumeroMagico();
  
		int aux=0;
		int* pares=obtenerPares();
   
		int* impares=obtenerImpares();


		*(*(cuadrado+1)+1)=*(numeros+4);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i%2==0&&j%2==0){
					if(*(numeros+4)%2==0){
						*(*(cuadrado+i)+j)=*(impares+aux);
						aux++;
					}
					else{
						*(*(cuadrado+i)+j)=*(pares+aux);
						aux++;
					}
				}
			}
		}

		*(*(cuadrado)+1)=numeroMagico-(*(*(cuadrado))+*(*(cuadrado)+2));
		*(*(cuadrado+1))=numeroMagico-(*(*(cuadrado))+*(*(cuadrado+2)));
		*(*(cuadrado+1)+2)=numeroMagico-(*(*(cuadrado)+2)+*(*(cuadrado+2)+2));
		*(*(cuadrado+2)+1)=numeroMagico-(*(*(cuadrado+2))+*(*(cuadrado+2)+2));
		
		imprimir();
        exportarTxt(2);
        numeroMagico = 0;
        inicio = auxiliar;
    }

    void metodoIII(){

        encerar();
        encerarMatriz();
        generarVect();
        obtenerNumeroMagico();

        llenarMatriz();
		for (int i = 0; i < f; i++) {
		    for (int j =0; j<c; j++) {
		    	if(i>0&&j>0&&i<4&&j<4){
		    		cuadrado[i-1][j-1]=matriz[i][j];
				}	
		    }
		}
		imprimirMatriz();
		cout<<endl;
		imprimir();
        exportarTxt(3);
        numeroMagico = 0;
        inicio = auxiliar;
    }


};