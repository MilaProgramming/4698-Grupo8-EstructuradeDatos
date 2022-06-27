#include <iostream>
using namespace std;


/*void imprimirDescendente(int A[],int tam){
	for(int i=tam;i>=0;i--){
		cout<<A[i]<<" , ";
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

void imprimirAscendente(int A[],int tam){
	for(int i=0;i<tam;i++){
		cout<<A[i]<<" , ";
	}
	cout<<""<<endl;
	cout<<""<<endl;
}

void quicksort(int A[],int izq, int der )
{ 
int i, j, x , aux; 
i = izq; 
j = der; 
x = A[ (izq + der) /2 ]; 
    do{ 
        while( (A[i] < x) && (j <= der) ){ 
            i++;
        } 
        while( (x < A[j]) && (j > izq) ){ 
            j--;
        } 
        if( i <= j ){ 
            aux = A[i]; A[i] = A[j]; A[j] = aux; 
            i++;  j--; 
        }
    }while( i <= j ); 
 
    if( izq < j ) 
        quicksort( A, izq, j ); 
    if( i < der ) 
        quicksort( A, i, der ); 
}

void intercambio(int numeros[], int tam){
	int aux;
	for(int i=0;i<tam-1;i++){
		for(int j=i+1;j<tam;j++){	
			if(numeros[i]>numeros[j]){
				aux=numeros[j];
				numeros[j]=numeros[i];
				numeros[i]=aux;
			}
			
		}
	}
}
*/
void imprimir(int A[],int tam){
	for(int i=0;i<tam;i++){
		cout<<A[i]<<" , ";
	}
	cout<<""<<endl;
	cout<<""<<endl;
}
/*TablaHash CrearTablaHash () {
   tLista *t;
   register i;

   t=(tLista *)malloc(NCASILLAS*sizeof(tLista));
   if (t==NULL)
      error("Memoria insuficiente.");

   for (i=0;i<NCASILLAS;i++)
      t[i]=crear();

   return t;
}

void DestruirTablaHash (TablaHash t){
   register i;

   for (i=0;i<NCASILLAS;i++)
      destruir(t[i]);

   free(t);
} 

void DestruirTablaHash (TablaHash t){
   register i;

   for (i=0;i<NCASILLAS;i++)
      destruir(t[i]);

   free(t);
} 

int MiembroHash (char *cad,TablaHash t){
   tPosicion p;
   int enc;	
   int pos=Hash(cad);
   
   p=primero(t[pos]);
   enc=O;
   while (p!=fin(t[pos]) && !enc) {
      if (strcmp(cad,elemento(p,t[pos]))==O)
         enc=1;
      else
         p=siguiente(p,t[pos]);
   }

   return enc;
}

void InsertarHash (char *cad,TablaHash t){
   int pos;

   if (MiembroHash(cad,t))
      return;

   pos=Hash(cad);
   insertar(cad,primero(t[pos]),t[pos]);
}

void BorrarHash (char *cad,TablaHash t){
   tPosicion p;
   int pos=Hash(cad);

   p=primero(t[pos]);
   while (p!=fin(t[pos]) && !strcmp(cad,elemento(p,t[pos])))
      p=siguiente(p,t[pos]));

   if (p!=fin(t[pos]))
      borrar(p,t[pos]);
}
*/
/*

void intercambiar(int *a, int *b){
   int temporal = *a;
  *a = *b;
  *b = temporal;
}


void burbuja(int arregloDinamico[], int longitud) {
  for (int i = 0; i < longitud; i++) 
  {
    for (int indiceActual = 0; indiceActual < longitud - 1; indiceActual++) 
	{
      int indiceSiguienteElemento = indiceActual + 1;
      if (arregloDinamico[indiceActual] > arregloDinamico[indiceSiguienteElemento]) 
	  {
        intercambiar(&arregloDinamico[indiceActual], &arregloDinamico[indiceSiguienteElemento]);
      }
    }
  }
}


void shellSort(int arregloDinamico[], int n) {
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = arregloDinamico[i];
      int j;
      for (j = i; j >= interval && arregloDinamico[j - interval] > temp; j -= interval) {
        arregloDinamico[j] = arregloDinamico[j - interval];
      }
      arregloDinamico[j] = temp;
    }
  }
}

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int tam, int place) {
  const int max = 10;
  int output[tam];
  int count[max];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < tam; i++)
    count[(array[i] / place) % 10]++;
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];
  for (int i = tam - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < tam; i++)
    array[i] = output[i];
}

void radixsort(int array[], int tam) {
  int max = getMax(array, tam);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, tam, place);
}


void binaria(int A[],int numero, int primero,int ultimo){
	int medio=(primero+ultimo)/2;
	while(primero<=ultimo){
		if(A[medio]<numero){
			primero=medio+1;
		}else if(A[medio]==numero){
			cout<<"Se encontro el numero en la posicion: "<<medio+1<<endl;
			break;
		}else{
			ultimo=medio-1;
		}
		medio=(primero+ultimo)/2;
	}
	
	if(primero>ultimo){
		cout<<"el numero "<<numero<<" no se encontro";
	}
}

int secuencial(int A[], int n, int x) {
	  for (int i = 0; i < n; i++)
	    if (A[i] == x)
	      return i;
	  return -1;
}*/