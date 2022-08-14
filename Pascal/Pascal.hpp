#include <iostream>
using namespace std;
#pragma once
   
class Pascal{

  private:
    int nivel;

  public:

  Pascal(int nivel): nivel(nivel){

  }
  
  ~Pascal(){

  }

  int factorial(int n){
    if (n < 1)
      return 1;
    else
      return n * factorial(n-1);
  }

  
  // se calcula el valor de la posicion del numero en
  // el vector utilizado el numero combinatorio
  int combinatorio(int a, int b){
    return factorial(a) / (factorial(b) * factorial(a-b));
  }

  void imprimir(){

    for (int i = 0; i <= nivel; i++){
    
      cout << "Nivel: " << i << "  ";
      for (int j = nivel - i; j > 0; j--){
        cout << " ";
      }
      for (int k = 0; k <= i; k++){
        cout << combinatorio(i, k) << " ";
      }
      cout << endl;
    }

  }


};