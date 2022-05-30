#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "3menu.cpp"
#include "3menu_option.cpp"
#include "1Lista.cpp"
#include "2IngresoDatos.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    Menu menu("Listas - menu");
    ListaEnlazada *l = new ListaEnlazada();


    menu.add_option(MenuOption("Agregar elemento al final", [&](MenuOptionArguments args) {
        IngresoDatos *v = new IngresoDatos();
        int valor;

        do {
            valor = v -> funcionPrincipal("Ingrese un valor: ");

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        l -> agregarFinal(valor);
        cout << "\n[elemento agregado]" <<endl;
    }));

    menu.add_option(MenuOption("Agregar elemento al inicio", [&](MenuOptionArguments args) {
        IngresoDatos *v = new IngresoDatos();
        int valor;

        do {
            valor = v -> funcionPrincipal("Ingrese un valor: ");

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        l -> agregarInicio(valor);
        cout << "\n[elemento agregado]" <<endl;
    }));

    menu.add_option(MenuOption("Eliminar Cabeza", [&](MenuOptionArguments args) {
        
        l ->eliminarCabeza();
        cout << "\n[elemento eliminado por la cabeza]" <<endl; 

    }));

    menu.add_option(MenuOption("Eliminar Cola", [&](MenuOptionArguments args) {
        
        l -> eliminarCola();
        cout << "\n[elemento eliminado por la cola]" <<endl; 

    }));    

    menu.add_option(MenuOption("Buscar", [&](MenuOptionArguments args) {
        IngresoDatos *v = new IngresoDatos();
        int valor;

        do {
            valor = v -> funcionPrincipal("Ingrese un valor: ");

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        if(l -> contiene(valor)){
         cout<< "\nEl indice del valor " << valor << " es " << l ->buscarIndice(valor) <<endl;
        }else{
         cout<< "\nNo existe ese valor en la lista" <<endl;   
        }
        
    }));
    

    menu.add_option(MenuOption("Imprimir Cabeza", [&](MenuOptionArguments args) {

        if (l->estaVacio()) {
            cout << "\n[lista vacia]" <<endl <<endl;
            return;
        }

        l->imprimirCabeza ();

    }));

    menu.add_option(MenuOption("Imprimir Cola", [&](MenuOptionArguments args) {
        if (l->estaVacio()) {
            cout << "[lista vacia]" <<endl <<endl;
            return;
        }

        l->imprimirCola ();

    }));

    //!Prueba de otras funciones
    menu.add_option(MenuOption("Otras funciones", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuInterno("Otras funciones");

        
        menuInterno.add_option(MenuOption("Buscar solo la primera ocurrencia", [&](MenuOptionArguments args) {
            if (l->estaVacio()) {
            cout << "\n[lista vacia]" <<endl <<endl;
            return;
            }
            cout<<"\nLa primera ocurrencia es " << l->buscarPrimerNodo() <<endl;
        }));
        

        menuInterno.add_option(MenuOption("Buscar si existe tal numero en la lista", [&](MenuOptionArguments args) {
            IngresoDatos *v = new IngresoDatos();
            int valor;

            do {
                valor = v -> funcionPrincipal("Ingrese un valor: ");

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
            break;
        } while (true);

            if(l -> estaVacio()){
                cout<< "\nLista vacia" <<endl; 
                return;
            }else{  

                if (l -> contiene(valor)){
                    cout << "\nExiste en valor en la lista" <<endl;
                }else{
                    cout << "\nNo existe el valor ingresado en la lista" <<endl;
                }    
            }
        }));

        menuInterno.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
            menuInterno.stop();
        }, false));

        menuInterno.display();
    }));

    menu.add_option(MenuOption("salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    menu.display(); 

    return 0; 
}

