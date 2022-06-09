
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

    //!Funciona menu completo
    menu.add_option(MenuOption("Stock", [&](MenuOptionArguments args) {
        system("CLS");
        //Submenu Stock
        Menu menuStock("Stock");

            //!Funciona
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

                        if(precio!= -1){

                            stock = k->funcionPrincipalEnteros("\nIngrese la cantidad de ejemplares de este celular que existen: ");    
                            
                            if(stock != -1){
                                Celular *nuevo = new Celular(marca, precio, stock);

                                tienda->agregarCelularTienda(nuevo);
                            }
                        }

                    }else{

                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                delete [] marca;
            }));

            //!Funciona
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

                        if(precio != -1){
                        Celular* celu = new Celular(nombre, precio, 0);
                        tienda->eliminarCelularTienda(celu);
                        }

                    }else{
                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                    delete [] nombre;

                }
            }));
            
            //!Funciona
            menuStock.add_option(MenuOption("Busqueda", [&](MenuOptionArguments args) {
       
                //Submenu Busqueda de Celulares
                Menu menuBusquedaUsuarios("Busqueda");

                    //!Funciona
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
                    
                    //!Funciona
                    menuBusquedaUsuarios.add_option(MenuOption("Por Precio", [&](MenuOptionArguments args) {
                       
                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        double precio;

                        precio = i->funcionPrincipalFlotantes("\nIngrese el nombre de la persona que desea buscar: ");    

                        if(precio != 1){
                            tienda->buscarPorPrecioCelular(precio);
                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                    }));
                    

                    
                    menuBusquedaUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                    menuBusquedaUsuarios.stop();
                    }, false));

                    //Mostrar menu
                    menuBusquedaUsuarios.display();



            }));

            //!Funciona
            menuStock.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuStock.stop();
            }, false));

            //Mostrar menu
            menuStock.display();

    }));


    menu.add_option(MenuOption("Usuarios ", [&](MenuOptionArguments args) {
    
        system("CLS");
        //Submenu Usuarios
        Menu menuUsuarios("Usuarios");

            menuUsuarios.add_option(MenuOption("Ver Usuarios", [&](MenuOptionArguments args) {
                tienda->getStock()->getPersonas()->imprimirObjetoFinal();
            }));

            //!Funciona
            menuUsuarios.add_option(MenuOption("Agregar Usuario", [&](MenuOptionArguments args) {   
                
                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *k = new IngresoDatos<int, float>();

                char* nombre = new char[50];
                nombre[0] = '\0';
                char* apellido = new char[50];
                apellido[0] = '\0';
                double presupuesto;

                nombre = i->funcionLetras("\nIngrese el nombre de la persona: ");

                    if(nombre[0] != '\0'){
                        apellido = j->funcionLetras("\nIngrese el apellido de la persona: ");

                        if(apellido[0] != '\0'){

                            presupuesto = k->funcionPrincipalFlotantes("\nIngrese el presupuesto de la persona: ");

                            if(presupuesto!= -1){

                                Persona *nueva = new Persona(nombre, apellido, presupuesto);  
                                
                                tienda->agregarPersonaTienda(nueva);
                            }

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }
                    }else{

                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                delete [] nombre;
                delete [] apellido;

            }));
            
            //!Funciona
            menuUsuarios.add_option(MenuOption("Eliminar Usuario", [&](MenuOptionArguments args) {
                
                if(tienda->estaVacio()){
                    cout<< "Tienda vacia. No hay nada que borrar" <<endl;
                }else{

                    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                    IngresoDatos<int, float> *j = new IngresoDatos<int, float>();

                    char* nombre = new char[50];
                    nombre[0] = '\0';
                    char* apellido = new char[50];
                    apellido[0] = '\0';
                    tienda->getStock()->verPersonas();
                    


                    nombre = i->funcionLetras("\nIngrese solo el nombre de la persona que desea eliminar: ");    

                    if(nombre[0] != '\0'){
                        
                        apellido = j ->funcionLetras("\nIngrese el apellido de la persona que desea eliminar: ");

                        if(apellido[0] != '\0'){
                            Persona* per = new Persona(nombre, apellido, 0);
                            tienda->eliminarPersonaTienda(per);
                        }

                    }else{
                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }

                    delete [] nombre;

                }


            }));

            //!Funciona
            menuUsuarios.add_option(MenuOption("Buscar Usuarios", [&](MenuOptionArguments args) {
                system("CLS");
                //Submenu Busqueda de Usuarios
                Menu menuBusquedaUsuarios("Busqueda");

                    //!Funciona
                    menuBusquedaUsuarios.add_option(MenuOption("Por Nombre", [&](MenuOptionArguments args) {
                        
                        if(tienda->estaVacio()){

                            cout<< "Tienda vacia. No hay nada que buscar" <<endl;

                        }else{

                            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                            IngresoDatos<int, float> *j = new IngresoDatos<int, float>();

                            char* nombre = new char[50];
                            nombre[0] = '\0';
                            char* apellido = new char[50];
                            apellido[0] = '\0';

                            
                            nombre = i->funcionLetras("\nIngrese solo el nombre que desea buscar: ");    
                            
                            if(nombre[0] != '\0'){

                                apellido = j->funcionLetras("\nIngrese solo el nombre que desea buscar: ");

                                if(nombre[0] != '\0'){
                                    tienda ->buscarPorNombrePersona(nombre, apellido);
                                }else{
                                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                }
            
                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }

                            delete [] nombre;
                            delete [] apellido;
                        }

                        
                        //Stock *porNombre = new Stock();
                        //porNombre->setPersonas(tienda->personasPorNombreIgual(nombre));
                        //porNombre->informeCompraCelulares();
                        
                    }));
                    
                    //!Funciona
                    menuBusquedaUsuarios.add_option(MenuOption("Por Presupuesto", [&](MenuOptionArguments args) {
                       
                        if(tienda->estaVacio()){

                            cout<< "Tienda vacia. No hay nada que buscar" <<endl;

                        }else{

                            IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                            double presupuesto;

                            presupuesto = i->funcionPrincipalFlotantes("\nIngrese el presupuesto de la persona que desea buscar: ");    

                            if(presupuesto != 1){
                                tienda->buscarPorPresupuestoPersona(presupuesto);
                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }    
                        }    

                    }));
                                
                    menuBusquedaUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                    menuBusquedaUsuarios.stop();
                    }, false));

                    //Mostrar menu
                    menuBusquedaUsuarios.display();
            }));

            //!Funciona
            menuUsuarios.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuUsuarios.stop();
            }, false));

            //Mostrar menu
            menuUsuarios.display();
    }));


    menu.add_option(MenuOption("Comprar", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuComprar("Comprar");  

            menuComprar.add_option(MenuOption("Recomendar compra", [&](MenuOptionArguments args) {
                system("CLS");

                //?Submenu Recomendaciones 

                Menu menuRecomendaciones("Recomendaciones");

                    system("CLS");
                    //Submenu Recomendar celulares 
                    Menu menuReCelulares("Submenu Recomendar Celulares");

                    menuReCelulares.add_option(MenuOption("Recomendar automaticamente", [&](MenuOptionArguments args) {
                        
                        if(tienda->estaVacio()){
                                cout<< "Tienda vacia. No hay nada que recomendar" <<endl;
                        }else{

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                        IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                        
                        char* nombre = new char[50];
                        nombre[0] = '\0';

                        char* apellido = new char[50];
                        nombre[0] = '\0';

                        nombre = i->funcionLetras("\nIngrese el nombre de la persona a la que desea recomendar un celular: ");    

                        if(nombre[0] != '\0'){
                            
                            apellido = j->funcionLetras("\nIngrese el apellido de la persona: ");

                            if(apellido[0] != '\0'){
                            
                            tienda->recomendarAutomatico(nombre, apellido);

                            system("pause");
        
                            system("CLS");
                            Menu menuInterno("~~~ Desea comprar alguno? ~~~");
                            
                            menuInterno.add_option(MenuOption("Si", [&](MenuOptionArguments args) {

                                    tienda->recomendarAutomatico(nombre, apellido);

                                    IngresoDatos<int, float> *o = new IngresoDatos<int, float>();
            
                                    char* celular = new char[50];
    
                                    celular = o->funcionMixta("\nIngrese el nombre del celular que desea comprar ");   

                                    if(celular[0] != '\0'){
                                    
                                        
                                    tienda->comprarCelular(celular, nombre, apellido);
                                            

                                    } else{
                                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                                    }
                                menuInterno.stop();
                            }, false));
                            

                            menuInterno.add_option(MenuOption("No", [&](MenuOptionArguments args) {
                                menuInterno.stop();
                            }, false));

                            menuInterno.display();

                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }
                        }else{
                           cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }    

                            delete [] nombre;
                            delete [] apellido;
                        }


                    }));
                    
                    menuReCelulares.add_option(MenuOption("Recomendar por presupuesto a mayor", [&](MenuOptionArguments args) {
                        
                        if(tienda->estaVacio()){
                                cout<< "Tienda vacia. No hay nada que recomendar" <<endl;
                        }else{

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                  
                        double presupuesto;

                        presupuesto = i->funcionPrincipalFlotantes("\nIngrese el presupuesto con el que desea trabajar: ");    

                            if(presupuesto != -1){
                                
                                tienda->recomendarMayores(presupuesto);
                            
                            }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }    
           
                        }


                    }));
                    
                    
                    menuReCelulares.add_option(MenuOption("Recomendar por presupuesto a menor", [&](MenuOptionArguments args) {
                       
                        if(tienda->estaVacio()){
                                cout<< "Tienda vacia. No hay nada que recomendar" <<endl;
                        }else{

                        IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                  
                        double presupuesto;

                        presupuesto = i->funcionPrincipalFlotantes("\nIngrese el presupuesto con el que desea trabajar: ");    

                            if(presupuesto != -1){
                                
                                tienda->recomendarMenores(presupuesto);
                            
                            }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            }    
           
                        }

                    }));

                    menuReCelulares.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                        menuReCelulares.stop();
                    }, false));

                    menuReCelulares.display();            
                

                menuRecomendaciones.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
                menuRecomendaciones.stop();
                }, false));

                menuRecomendaciones.display();
            }));


            menuComprar.add_option(MenuOption("Comprar celular", [&](MenuOptionArguments args) {
                    
                IngresoDatos<int, float> *i = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *j = new IngresoDatos<int, float>();
                IngresoDatos<int, float> *k = new IngresoDatos<int, float>();

                tienda->getStock()->verStock();

                char* celular = new char[50];
                celular[0] = '\0';
                char* persona = new char[50];
                persona[0] = '\0';
                char* apersona = new char[50];
                apersona[0] = '\0';

                    celular = i->funcionMixta("\nIngrese el nombre del celular que desea comprar ");   

                    if(celular[0] != '\0'){
                    
                        system("cls");
                        cout<< "\n \n" <<endl;
                        tienda->getStock()->getPersonas()->imprimirObjetoFinal();


                        persona = j->funcionLetras("\nIngrese el nombre de la persona que comprara: ");    

                        if(persona[0] != '\0'){

                            apersona = k -> funcionLetras("\nIngrese el apellido de la persona que comprara: ");

                            if(apersona[0] != '\0'){
                                tienda->comprarCelular(celular, persona, apersona);
                            }else{
                                cout<<"\n~~ Datos vacios ~~\n"<<endl;
                            } 

                        }else{
                            cout<<"\n~~ Datos vacios ~~\n"<<endl;
                        }

                    } else{
                        cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    }
                 
            }));


            menuComprar.add_option(MenuOption("Regresar a menu principal", [&](MenuOptionArguments args) {
            menuComprar.stop();
            }, false));

        menuComprar.display();
    }));

   

    menu.add_option(MenuOption("Mostrar informe de compras", [&](MenuOptionArguments args) {
        tienda->getStock()->informeCompraCelulares();
    }));


    //!Funcion salida del menu
    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        tienda->~Tienda();
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

Tienda* datosDefecto(){

    Persona *p1 = new Persona("Matias", "Manzin", 100);
    Persona *p2 = new Persona("Lionel", "Messi", 5000);
    Persona *p3 = new Persona("Edward", "Tech", 1500);

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

