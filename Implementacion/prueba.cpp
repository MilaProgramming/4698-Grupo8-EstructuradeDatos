#include <iostream>
using namespace std;
#include <math.h>

int main(){

    char* a = new char[11];
    char* b = new char[11];

    char cont = 'a';
    char ahre = '1';
    for(int o = 0; o< 10; o++){
        a[o] = ahre;
        ahre++;
    }

    char u = '1';
    for(int o = 0; o< 10; o++){
        b[o] = u;
        u++;
    }

    for(int o = 0; o< 10; o++){
       cout<< a[o] << " "; 
        
    }
    cout<< "\n";
     for(int o = 0; o< 10; o++){
       cout<< b[o] << " "; 
        
    }

    int p = 0;
    int e = 0;

    while(e == 0){

        for(int o = 0; o < 11; o++){
            if(a[o] == b[o]){
                p++;
                cout << "Entro condicion" <<endl;
            }
        }

        e++;
    }

    cout << p <<endl;

    cout<< a <<endl;

    double y = 2783.2324;

}