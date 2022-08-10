#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;
#pragma once
   
class CuadradoMagico{

    private:
        int** cuadrado; //Nombre del cuadro donde se encuentra la respuesta
        int** matriz; //Matriz amplificada para el metodo III 
        int* numeros; //Vector auxiliar para el metodo II
        int inicio{0}; //Numero inicial para metodo I y III
        fstream archivo;
        int n{3}; // Dimension para metodo I
        int m{15}; // Numero magico para metodo
        int numeroMagico{0}; // Numero magico para metodo II y III
        int f{5}, c{5}; //Enteros para el metodo III

        void generarVector(){
            for(int i=0;i<11;i++){
                if(i==3||i==7){
                    numeros[i]=0;
                }else{
                    numeros[i]=inicio++;
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
                            matriz[cont1-1][n-cont1]=numeros[cont2];				    	
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
                        matriz[fila+cont1][colum-cont1]=numeros[cont2];
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

        void  imprimirMatriz(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << *(*(matriz + i) + j) << " ";
                }
                cout <<endl;
            }
            cout <<endl;
        }


        /**
         * Establece todos los valores en la matriz a 0
         */
        void encerar(){

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    *(*(cuadrado + i) + j) = 0;
                }
            }

        }

        /**
         * Devuelve verdadero si el valor en la posición dada no es 0
         * 
         * @param i fila
         * @param j columna
         * 
         * @return E; valor de verdad del enunciado.
         */
        bool estaOcupado(int i, int j){
            return *(*(cuadrado + i) + j) != 0;
        }

        /**
         * Toma dos punteros a números enteros, y si los números enteros son menores que cero o mayores
         * o iguales al tamaño de la matriz, los establece en el valor correcto
         * 
         * @param i el índice de la fila
         * @param j columna
         */
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

        /**
         * Imprime el contenido de la matriz.
         */
        void imprimir(){

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << *(*(cuadrado + i) + j) << " ";
                }
                cout <<endl;
            }
            cout <<endl;
        }

        /**
         * Abre un archivo, escribe en él y lo cierra.
         * 
         * @param metodo 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
         * 23, 24, 25, 26, 27, 28, 29, 30,
         */
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
            int* impares=new int[4];
            int aux=0;
            for(int i=0;i<pow(n,2);i++){
                if(*(numeros+i)%2!=0){
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
	
    public:

    CuadradoMagico(int inicio): cuadrado(new int*[3]), inicio(inicio), numeros(new int[(int)pow(n,2)]){

        for(int i = 0; i < 3; i++)
                *(cuadrado + i) = new int[3];

        for(int i=0;i<pow(3,2);i++)
			    *(numeros+i)=inicio+i;
		
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
    }

    void metodoIII(){
        encerar();

        llenarMatriz();
        for (int i = 0; i < f; i++) {
            for (int j =0; j<c; j++) {
                if(i>0 && j>0 && i<4 && j<4){
                    cuadrado[i-1][j-1]=matriz[i][j];
                }	
            }
        }
        imprimirMatriz();
        cout<<endl;
        imprimir();
        exportarTxt(3);
    }

};