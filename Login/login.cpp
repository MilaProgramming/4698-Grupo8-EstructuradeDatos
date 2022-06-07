#include <iostream>
#include <string>
#include <cstdlib>
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
        cout<< "\n\tUsuario: "; 
        getline(cin, usuario);
        cout<< "\n\tPassword: "; 
        getline(cin, password);

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