#include <iostream>
#include "Numero.h"
#include <vector>
#include <cstring>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using std::vector;
using namespace std;

Numero::Numero(string s){
    this -> nums = creacionVector(s);
}

vector<int> Numero::creacionVector(string s){
    vector<int> nums;
    int num = 1;
    std::cout << "\n"<< s << std::endl;
    std::cout << "Si ha terminado, escriba \"0\" " << std::endl;
    
    while (num != 0){
        std::cin >> num;
        if (num != 0){
            nums.push_back(num);
        }
    }

    return nums;
}

int euclidesMCD(int A, int B){

    if (A == 0){
        return B;
    }else if (B == 0){
        return A;
    }else{
        return euclidesMCD(B, A%B);
    }
    
}

void Numero::imprimirLongitudVector(){
    std::cout << "Longitud del vector: " << nums.size() << std::endl;
}

void Numero::imprimirDatosVector(){
    std::cout << "Numeros en el vector\n " <<  std::endl;
    for (auto i = nums.begin(); i != nums.end(); ++i)
        std::cout << *i << " ";
}
