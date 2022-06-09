#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
//#include <main.cpp>
#define USER "admin"
#define PASSWORD "admin"

using namespace std;

int main (){
    string usuario, password;
    int contador = 0;
    bool ingreso = false;

    do{
        system("cls");

        cout<<"\t\t\tLOGIN DE USUARIO"<<endl;
        cout<<"\t\t\t----------------"<<endl;

        //Usuario
        cout<< "\n\tUsuario: "; 
        getline(cin, usuario);

        //Contraseña
        cout<< "\n\tPassword: "; 
        //getline(cin, password);
        char caracter;
        caracter= getch();
        password="";

        //Lectura hasta precionar enter
        while (caracter != 13){
            if(caracter != 8){
            password.push_back(caracter);
            cout<<"*";
            }else{
                if(password.length()>0){
                cout<<"\b \b";
                password = password.substr(0, password.length()-1);
                }
            }
            caracter= getch();
        }

        //Condicion
        if( usuario ==USER && password == PASSWORD){
            ingreso=true;

        } else{
            cout<<"\n\tEl usuario y/o password son incorrectos"<<endl;
            cin.get();
            contador++;
        }
    }while (ingreso == false && contador<3);

    if(ingreso == false){
        cout <<"\n\tNo se pudo ingresar al sistema"<<endl;
    }else{
        cout<<"\n\tBienvenido al sistema"<<endl;

        //Operaciones
        
    }
    
    cin.get();
    cin.get();






    return 0;
}