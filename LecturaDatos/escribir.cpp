#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(){

    char* a = new char[50];

    cout<<"Nombre del archivo que desea leer: ";
    cin>>a; //Se arrastra el txt que se requiere
    ofstream myfile;
    myfile.open (a, ios::app);

    
    if (myfile.is_open())
    {
        myfile << "Titulo\n";
        myfile << "1\n";
        myfile << "2\n";
        myfile << "3\n";
        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
}

