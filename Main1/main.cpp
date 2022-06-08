
//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H
//!EJEMPLO DE CREACION DE MENU

#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "4Menu.cpp"
#include "4OpcionMenu.cpp"
#include "3Tienda.cpp"
#include "3Stock.cpp"
#include "5IngresoDatos.hpp"

#include <iostream>

using namespace std;

Tienda* datosDefecto();

int main(int argc, char **argv) {
    
    Tienda *tienda = datosDefecto();
    Tienda *tiendaVacia = new Tienda();

    //!Creo objeto menu. Este manejara las opciones
    Menu menu("------- Bienvenidos al programa de compra de Celulares -------");

   
    menu.add_option(MenuOption("Stock", [&](MenuOptionArguments args) {
        system("CLS");
        //Submenu Stock
        Menu menuStock("Stock");

            menuStock.add_option(MenuOption("Ver Stock", [&](MenuOptionArguments args) {
                tienda->getStock()->verCelulares();
            }));

            menuStock.add_option(MenuOption("Agregar a Stock", [&](MenuOptionArguments args){

                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *k = new IngresoDatos<int, float>();

                char* marca;
                double precio;
                int stock;

                do{

                        marca = i->funcionMixta("\nIngrese la marca del celular: ");

                        precio = j->funcionPrincipalFlotantes("\nIngrese el precio del celular: ");

                        stock = k->funcionPrincipalEnteros("\nIngrese la cantidad de ejemplares de este celular que existen: ");
                    

                        break;
                } while (true);

                    
                Celular *nuevo = new Celular(marca, precio, stock);


                if(tienda->getStock()->compararCelulares(nuevo)){
                    cout<< "\n \n \n";
                    tienda->getStock()->agregarStockRepetido(nuevo, nuevo->getStock());
                    tienda->getStock()->verCelulares();
                    cout << "\nEl celular que desea agregar ya existe. Se ha aumentado el stock" <<endl;

                }else{
                    cout<< "\n \n \n";
                    tienda->getStock()->getCelulares()->insertarFinal(nuevo);
                    tienda->getStock()->verCelulares();
                }


            }));

            menuStock.add_option(MenuOption("Eliminar elemento del Stock", [&](MenuOptionArguments args) {

                if(tienda->estaVacio()){
                    cout<< "Tienda vacia. No hay nada que borrar" <<endl;
                }else{
                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                    char* nombre;
                    tienda->getStock()->verCelulares();
                    do{

                        nombre = i->funcionMixta("\nIngrese el nombre del celular que desea eliminar: ");    

                        break;
                    } while (true);

                    tienda->getStock()->eliminarCelularNombre(nombre);
                    tienda->getStock()->verCelulares();

                }
            }));
        
            menuStock.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
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


    menu.add_option(MenuOption("Usuarios ", [&](MenuOptionArguments args) {
    
        system("CLS");
        //Submenu Usuarios
        Menu menuUsuarios("Usuarios");

            menuUsuarios.add_option(MenuOption("Ver Usuarios", [&](MenuOptionArguments args) {
                tienda->getStock()->getPersonas()->imprimirObjetoFinal();
            }));

            menuUsuarios.add_option(MenuOption("Buscar Usuarios", [&](MenuOptionArguments args) {
                system("CLS");
                //Submenu Busqueda de Usuarios
                Menu menuBusquedaUsuarios("Busqueda");

                    menuBusquedaUsuarios.add_option(MenuOption("Por Nombre", [&](MenuOptionArguments args) {
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        char* nombre;

                        do{

                        nombre = i->funcionMixta("\nIngrese el nombre de la persona que desea buscar: ");    

                        break;
                    } while (true);

                        Stock *porNombre = new Stock();
                        porNombre->setPersonas(tienda->personasPorNombreIgual(nombre));
                        porNombre->informeCompraCelulares();
                        
                    }));
                    
                    menuBusquedaUsuarios.add_option(MenuOption("Por Presupuesto", [&](MenuOptionArguments args) {
                       
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        double presupuesto;

                        do{

                        presupuesto = i->funcionPrincipalFlotantes("\nIngrese el nombre de la persona que desea buscar: ");    

                        break;
                    } while (true);

                        Stock *porNombre = new Stock();
                        porNombre->setPersonas(tienda->personasPorPresupuestoIgual(presupuesto));
                        porNombre -> informeCompraCelulares();

                    }));
                    

                    
                    menuBusquedaUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                    menuBusquedaUsuarios.stop();
                    }, false));

                    //Mostrar menu
                    menuBusquedaUsuarios.display();
            }));

            menuUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuUsuarios.stop();
            }, false));

            //Mostrar menu
            menuUsuarios.display();
    }));


    //!Submenus
    menu.add_option(MenuOption("Comprar", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuComprar("Comprar");  

            menuComprar.add_option(MenuOption("Recomendar compra", [&](MenuOptionArguments args) {
                system("CLS");
                //Submenu Recomendaciones 
                Menu menuRecomendaciones("Recomendaciones");

                menuRecomendaciones.add_option(MenuOption("Recomendar celulares para comprar", [&](MenuOptionArguments args) {
                    system("CLS");
                    //Submenu Recomendar celulares 
                    Menu menuReCelulares("Submenu Recomendar Celulares");

                    menuReCelulares.add_option(MenuOption("Recomendar automaticamente", [&](MenuOptionArguments args) {
                    
                    }));
                    
                    menuReCelulares.add_option(MenuOption("Recomendar por presupuesto a mayor", [&](MenuOptionArguments args) {
                    
                    }));
                    
                    
                    menuReCelulares.add_option(MenuOption("Recomendar por presupuesto a menor", [&](MenuOptionArguments args) {
                    
                    }));

                    menuReCelulares.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                        menuReCelulares.stop();
                    }, false));

                    menuReCelulares.display();            
                }));

                menuRecomendaciones.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                menuRecomendaciones.stop();
                }, false));

                menuRecomendaciones.display();
            }));


            menuComprar.add_option(MenuOption("Comprar celular", [&](MenuOptionArguments args) {
                    
                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                tienda->getStock()->verStock();
                char* nombre;

                    do{

                        nombre = i->funcionMixta("\nIngrese el nombre del celular que desea comprar ");    

                        break;
                    } while (true);

                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                cout<< "\n \n" <<endl;
                tienda->getStock()->getPersonas()->imprimirObjetoFinal();
                char* nombre1;

                    do{

                        nombre1 = j->funcionMixta("\nIngrese el nombre de la persona que comprara: ");    

                        break;
                    } while (true);

                Celular *c = tienda->getStock()->retornarCelularporNombre(nombre);
                Persona *p = tienda->getStock()->retornarPersonaporNombre(nombre1);

                p -> comprarCelular(c);
                 
            }));


            menuComprar.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuComprar.stop();
            }, false));

        menuComprar.display();
    }));


    //!Funcion salida del menu
    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

Tienda* datosDefecto(){

    Persona *p1 = new Persona("Matias Manzin", 100);
    Persona *p2 = new Persona("Lionel Messi", 5000);
    Persona *p3 = new Persona("Edward Tech", 1500);

    Celular *c1 = new Celular("Alcatel TCL A3", 40, 100);
    Celular *c2 = new Celular("Samsung Galaxy S22", 1000, 30);
    Celular *c3 = new Celular("Motorola One 5G Ace", 250, 50);
    Celular *c4 = new Celular("Iphone 12", 2000, 3);

    ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
    personas->insertarFinal(p1);
    personas->insertarFinal(p2);
    personas->insertarFinal(p3);

    ListaDobleC<Celular*> *celulares = new ListaDobleC<Celular*>();
    celulares->insertarFinal(c1);
    celulares->insertarFinal(c2);
    celulares->insertarFinal(c3);
    celulares->insertarFinal(c4);

    Stock *stock = new Stock();
    stock->setCelulares(celulares);
    stock->setPersonas(personas);

    Tienda *tienda = new Tienda();
    tienda->setStock(stock);

    return tienda;
}
