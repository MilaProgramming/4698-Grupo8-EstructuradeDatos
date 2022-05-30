#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "menu.cpp"
#include "menu_option.cpp"
//#include "Lista.h"
#include "Lista.cpp"
#include "IngresoDatos.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    Menu menu("Listas - menu");
    //LinkedList<int> list;
    //ListaEnlazada<int> list;
    ListaEnlazada *l = new ListaEnlazada();


    menu.add_option(MenuOption("Agregar elemento al final", [&](MenuOptionArguments args) {
        int value;

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        l -> agregarFinal(value);
        std::cout << "[elemento agregado]" << std::endl;
    }));

    menu.add_option(MenuOption("Agregar elemento al inicio", [&](MenuOptionArguments args) {
        int value;

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        l -> agregarInicio(value);
        std::cout << "[elemento agregado]" << std::endl;
    }));

    /*menu.add_option(MenuOption("Eliminar elemento", [&](MenuOptionArguments args) {
        if (l->estaVacio()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            system("pause");
            return;
        }

        Menu items_menu("Seleccione el elemento a eliminar: ");

        list.for_each([&](int element, int index) {
            MenuOptionArguments arguments;
            arguments.add("index", index);

            MenuOption option(std::to_string(index) + ": " + std::to_string(element), [&](MenuOptionArguments args) {
                list.remove_at(args.get<int>("index"));
                items_menu.stop();

                std::cout << "[elemento eliminado]" << std::endl;
            }, arguments);

            items_menu.add_option(option);
        });

        items_menu.add_option(MenuOption("regresar", [&](MenuOptionArguments args) {
            items_menu.stop();
        }, false));

        items_menu.display();
    }, false));*/
    menu.add_option(MenuOption("Eliminar Cabeza", [&](MenuOptionArguments args) {
        do {
            l ->eliminarCabeza();

        } while (true);
        std::cout << "[elemento eliminado]" << std::endl; 

    }));

    menu.add_option(MenuOption("Eliminar Cola", [&](MenuOptionArguments args) {
        do {
            l ->eliminarCola();

        } while (true);
        std::cout << "[elemento eliminado]" << std::endl; 

    }));    

    /*menu.add_option(MenuOption("Buscar elemento", [&](MenuOptionArguments args) {
        int value;

        if (l->estaVacio()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            return;
        }

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        int found_index;
        Node<int> *found = list.find([&](int element, int index) {
            found_index = index;
            return value == element;
        });

        if (found == nullptr) {
            std::cout << "elemento no encontrado" << std::endl;
        } else {
            std::cout << "elemento encontrado en la posicion " << found_index << std::endl;
        }
    }));*/

    menu.add_option(MenuOption("Buscar ", [&](MenuOptionArguments args) {
        int value;

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        l ->buscarIndice(value);
        
    }));
    

    menu.add_option(MenuOption("Imprimir Cabeza", [&](MenuOptionArguments args) {
        if (l->estaVacio()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            return;
        }

        l->imprimirCabeza ();

    }));

    menu.add_option(MenuOption("Imprimir Cola", [&](MenuOptionArguments args) {
        if (l->estaVacio()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            return;
        }

        l->imprimirCola ();

    }));


    menu.add_option(MenuOption("salir", [&](MenuOptionArguments args) {
        std::cout << "bye bye" << std::endl;
        menu.stop();
    }, false));

    menu.display(); 

    return 0; 
}

