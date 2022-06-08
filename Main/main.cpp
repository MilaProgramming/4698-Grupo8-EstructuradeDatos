
//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H
//!EJEMPLO DE CREACION DE MENU

#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "4Menu.cpp"
#include "4OpcionMenu.cpp"
#include "3Tienda.cpp"
#include "3Stock.cpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
   
    //!Creo objeto menu. Este manejara las opciones
    Menu menu("---Bienvenidos---");

   
    menu.add_option(MenuOption("1. Stock", [&](MenuOptionArguments args) {
        system("CLS");
        //Submenu Stock
        Menu menuStock("Submenu Stock");

            menuStock.add_option(MenuOption("1. Ver Stock", [&](MenuOptionArguments args) {
            }));
            menuStock.add_option(MenuOption("2. Agregar Stock", [&](MenuOptionArguments args) {
            }));
            menuStock.add_option(MenuOption("3. Eliminar Stock", [&](MenuOptionArguments args) {
            }));
        
            menuStock.add_option(MenuOption("\n4. Regresar a menu principal", [&](MenuOptionArguments args) {
            menuStock.stop();
            }, false));

            //Mostrar menu
            menuStock.display();
       
        /*do {

            //!Recibo datos de teclado. Me funciona para validar
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);*/

    }));


    menu.add_option(MenuOption("2. Usuarios ", [&](MenuOptionArguments args) {
        //!realizo una accion que no requiere input manual.
        system("CLS");
        //Submenu Usuarios
        Menu menuUsuarios("Submenu Usuarios ");

            menuUsuarios.add_option(MenuOption("1. Ver Usuarios", [&](MenuOptionArguments args) {
            }));
            menuUsuarios.add_option(MenuOption("2. Buscar Usuarios", [&](MenuOptionArguments args) {
                system("CLS");
                //Submenu Busqueda de Usuarios
                Menu menuBusquedaUsuarios("Submenu Busqueda ");

                    menuBusquedaUsuarios.add_option(MenuOption("1. Por Nombre", [&](MenuOptionArguments args) {
                    }));
                    menuBusquedaUsuarios.add_option(MenuOption("2. Por Presupuesto", [&](MenuOptionArguments args) {
                    }));
            }));        
            menuUsuarios.add_option(MenuOption("\n3. Regresar a menu principal", [&](MenuOptionArguments args) {
            menuUsuarios.stop();
            }, false));

            //Mostrar menu
            menuUsuarios.display();
    }));


    //!Submenus
    menu.add_option(MenuOption("3. Comprar", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuComprar("Submenu Comprar");        
            menuComprar.add_option(MenuOption("1...", [&](MenuOptionArguments args) {
            }));

            menuComprar.add_option(MenuOption("\n2. Regresar a menu principal", [&](MenuOptionArguments args) {
            menuComprar.stop();
            }, false));

        menuComprar.display();
    }));

    menu.add_option(MenuOption("4. Recomendaciones", [&](MenuOptionArguments args) {
        system("CLS");
        //Submenu Recomendaciones 
        Menu menuRecomendaciones("Submenu Recomendaciones");

            menuRecomendaciones.add_option(MenuOption("1. Recomendar celulares para comprar", [&](MenuOptionArguments args) {
                system("CLS");
                //Submenu Recomendar celulares 
                Menu menuReCelulares("Submenu Recomendar Celulares");

                menuReCelulares.add_option(MenuOption("1. Recomendar automaticamente", [&](MenuOptionArguments args) {
                }));
                menuReCelulares.add_option(MenuOption("2. Recomendar por presupuesto", [&](MenuOptionArguments args) {
                }));
                menuReCelulares.add_option(MenuOption("\n3. Regresar a menu principal", [&](MenuOptionArguments args) {
                menuReCelulares.stop();
                }, false));

                menuReCelulares.display();            
            }));
            menuRecomendaciones.add_option(MenuOption("\n2. Regresar a menu principal", [&](MenuOptionArguments args) {
            menuRecomendaciones.stop();
            }, false));

        menuRecomendaciones.display();
    }));

    //!Funcion salida del menu
    menu.add_option(MenuOption("5. salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

