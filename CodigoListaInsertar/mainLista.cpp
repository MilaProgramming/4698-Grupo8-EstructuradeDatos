#include "Lista.cpp"
#include "IngresoDatos.cpp"
#include <iostream>
using namespace std;

int main(){

    ListaEnlazada *l = new ListaEnlazada();

    /*
    IngresoDatos *i = new IngresoDatos();
    IngresoDatos *m = new IngresoDatos();
    int cont = 0;

    while (cont != 2){
        cont = 0;
        cout<< "Que desea realizar?\n";
        cout<< "1) Agregar datos\n";
        cout<< "2) Parar y ver la impresion\n";
        cont = m -> funcionPrincipal();

        if (cont == 1){
            l ->agregarFinal(i ->funcionPrincipal("\n Ingrese sus datos: "));
            system("CLS"); //Limpio pantalla
        }else if (cont ==2){
            cout<<"\n Sus datos son \n";
        }else{
            cout<<"Ingrese un numero valido\n";
        }
    }
    */


    l -> agregarFinal(10);
    l -> agregarFinal(15);
    l -> agregarFinal(20);

    l -> agregarInicio(5);
    l -> agregarFinal(25);
    
    l -> agregarInicio(0);
    l -> agregarFinal(30);

    l -> imprimirCabeza();

    cout << "\n";
    l -> imprimirCola();

    return 0;
}