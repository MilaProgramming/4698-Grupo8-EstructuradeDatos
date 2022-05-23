//#include "Numero.cpp"
#include <vector>
#include <iostream>
using std::vector;
using namespace std;

int euclidesMCD(int A, int B);
int euclidesMCD(int A, int B){

    if (A == 0){
        return B;
    }else if (B == 0){
        return A;
    }else{
        return euclidesMCD(B, A%B);
    }
    
}


int sumarT(vector<int>);
int sumarT(vector<int> nums) {
   auto i = nums.begin();
   int total = *i;
    ++i;
    
    for ( i; i != nums.end(); ++i) {
        total = euclidesMCD(total, *i); 
    }

    return total;
}


int main(){

    // !Funciona bien
    //Numero *c = new Numero("Ingrese los numeros con los que desea trabajar");
    //c ->imprimirLongitudVector();
    //c ->imprimirDatosVector();

  
    vector<int> g1;
    int num=1;
    std::cout << "Si ha terminado, escriba \"0\" " << std::endl;
    
    while (num != 0){
        std::cin >> num;
        if (num != 0){
            g1.push_back(num);
        }
    }

    for (auto i = g1.begin(); i != g1.end(); ++i){
        cout << *i << " ";
    }

    printf("%i", sumarT(g1));
   
}

