
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
    //Tienda *tiendaVacia = new Tienda();

    //!Creo objeto menu. Este manejara las opciones
    Menu menu("------- Bienvenidos al programa de compra de Celulares -------");

   
    menu.add_option(MenuOption("Stock", [&](MenuOptionArguments args) {
        system("CLS");
        //Submenu Stock
        Menu menuStock("Stock");

            menuStock.add_option(MenuOption("Ver Stock", [&](MenuOptionArguments args) {
                tienda->getStock()->verCelulares();
                //tienda->getStock()->verStock();
                //cout<<tienda->getStock()->getCelulares()->obtenerLongitud()<<endl;
            }));


            //!Funciona
            menuStock.add_option(MenuOption("Agregar a Stock", [&](MenuOptionArguments args){

                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *k = new IngresoDatos<int, float>();

                char* marca = new char[50];
                marca[0] = '\0';
                double precio;
                int stock;

                marca = i->funcionMixta("\nIngrese la marca del celular: ");

                    if(marca[0] != '\0'){

                        precio = j->funcionPrincipalFlotantes("\nIngrese el precio del celular: ");

                        stock = k->funcionPrincipalEnteros("\nIngrese la cantidad de ejemplares de este celular que existen: ");

                        Celular *nuevo = new Celular(marca, precio, stock);

                        tienda->agregarCelularTienda(nuevo);

                    }else{

                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                delete [] marca;
            }));

            menuStock.add_option(MenuOption("Eliminar elemento del Stock", [&](MenuOptionArguments args) {

                if(tienda->estaVacio()){
                    cout<< "Tienda vacia. No hay nada que borrar" <<endl;
                }else{

                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                    IngresoDatos<int, float> *j = new IngresoDatos<int, float>();

                    char* nombre = new char[50];
                    nombre[0] = '\0';
                    double precio;
                    tienda->getStock()->verCelulares();
                    


                    nombre = i->funcionMixta("\nIngrese el nombre del celular que desea eliminar: ");    

                    if(nombre[0] != '\0'){
                        
                        precio = j->funcionPrincipalFlotantes("\nIngrese el precio del celular que desea eliminar: ");

                        Celular* celu = new Celular(nombre, precio, 0);
                        tienda->eliminarCelularTienda(celu);

                    }else{
                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                    delete [] nombre;

                }
            }));

            menuStock.add_option(MenuOption("Busqueda", [&](MenuOptionArguments args) {
       
                //Submenu Busqueda de Celulares
                Menu menuBusquedaUsuarios("Busqueda");

                    menuBusquedaUsuarios.add_option(MenuOption("Por Marca", [&](MenuOptionArguments args) {
                        
                        if(tienda->estaVacio()){

                            cout<< "Tienda vacia. No hay nada que buscar" <<endl;

                        }else{

                            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                            char* nombre = new char[50];
                            nombre[0] = '\0';

                            
                            nombre = i->funcionMixta("\nIngrese la marca del celular que desea buscar: ");    

                            if(nombre[0] != '\0'){
                                tienda ->buscarPorNombreCelular(nombre);
                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                            delete [] nombre;
                        }
                        
                    }));
                    
                    menuBusquedaUsuarios.add_option(MenuOption("Por Precio", [&](MenuOptionArguments args) {
                       
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        double presupuesto;

                        presupuesto = i->funcionPrincipalFlotantes("\nIngrese el nombre de la persona que desea buscar: ");    

                        tienda->buscarPorPrecioCelular(presupuesto);

                    }));
                    

                    
                    menuBusquedaUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                    menuBusquedaUsuarios.stop();
                    }, false));

                    //Mostrar menu
                    menuBusquedaUsuarios.display();



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
                        
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        //tienda->getStock()->ordenarPorPrecio();
                        char* nombre;

                        do{

                        nombre = i->funcionMixta("\nIngrese el nombre de la persona a la que desea recomendar un celular: ");    

                        break;
                        } while (true);

                        //tienda->getStock()->ordenarPorPrecio();
                        Stock *por = new Stock();
                        por -> setPersonas(tienda->personasPorNombreIgual(nombre));
                        por -> setCelulares(tienda->recomendarCelulares(tienda->getStock()->getPersonas()->obtenerPrimero()->getValor()));
                        
                        por -> verStock();

                    }));
                    
                    menuReCelulares.add_option(MenuOption("Recomendar por presupuesto a mayor", [&](MenuOptionArguments args) {
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        double p;

                        do{

                        p = i->funcionPrincipalFlotantes("\nIngrese el presupuesto con el que desea trabajar: ");    

                        break;
                        } while (true);

                        //tienda->getStock()->ordenarPorPrecio();
                        Stock *porNomb = new Stock();
                        porNomb -> setCelulares(tienda -> celularesPorPresupuestoMayor(p));
                        
                        porNomb -> verStock();
                    }));
                    
                    
                    menuReCelulares.add_option(MenuOption("Recomendar por presupuesto a menor", [&](MenuOptionArguments args) {
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        double p;

                        do{

                        p = i->funcionPrincipalFlotantes("\nIngrese el presupuesto con el que desea trabajar: ");    

                        break;
                        } while (true);

                        //tienda->getStock()->ordenarPorPrecio();
                        Stock *porNombr = new Stock();
                        porNombr -> setCelulares(tienda -> celularesPorPresupuestoMenor(p));
                        
                        porNombr -> verStock();
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
                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();

                tienda->getStock()->verStock();

                char* celular = new char[50];
                celular[0] = '\0';
                char* persona = new char[50];
                persona[0] = '\0';

                    celular = i->funcionMixta("\nIngrese el nombre del celular que desea comprar ");    
                    if(celular[0] != '\0'){
                    
                        system("cls");
                        cout<< "\n \n" <<endl;
                        tienda->getStock()->getPersonas()->imprimirObjetoFinal();


                        persona = j->funcionMixta("\nIngrese el nombre de la persona que comprara: ");    

                        if(persona[0] != '\0'){
                            tienda->comprarCelular(celular, persona);
                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                    } else{
                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }
                 
            }));


            menuComprar.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuComprar.stop();
            tienda->~Tienda();
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

    Celular *c1 = new Celular("Alcatel", 40, 100);
    Celular *c2 = new Celular("Samsung", 1000, 30);
    Celular *c3 = new Celular("Motorola", 250, 50);
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

