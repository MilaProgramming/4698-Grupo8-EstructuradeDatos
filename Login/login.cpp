#include <iostream>
#include <string>
#define USER "admin"
#define PASSWORD "admin"

using namespace std;

int main (){
    string usuario, password;
    int contador = 0;
    bool ingreso = false;

    do{
        cout<<"\t\t\tLOGIN DE USUARIO"<<endl;
        cout<<"\t\t\t----------------"<<endl;
        cout<< "\n\tUsuario: "; 
        getline(cin, usuario);
        cout<< "\n\tPassword: "; 
        getline(cin, password);

        if( usuario ==USER && password == PASSWORD){
            cout<<"\n\tBienvenido al Sistema";

        } else{
            cout<<"\n\tEl usuario y/o password son incorrectos"<<endl;
            contador++;
        }
    }while (ingreso == false && contador<3);

    if(ingreso == false){
        cout <<"\n\tNo se pudo ingresar al sistema";
    }else{
        cout<<"\n\tBienvenido al sistema"<<endl;
    }
    
    cin.get();
    cin.get();






    return 0;
}