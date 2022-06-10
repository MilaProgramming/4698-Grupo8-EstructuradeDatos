#pragma once
#include "3Tienda.h"
#include "3Celular.cpp"
#include "1NodoDC.h"

    //Constructor y destructor
    Tienda::Tienda(){

    }

    Tienda::~Tienda(){
        free(this);
        stock->~Stock();
    }

    //Funciones de excepciones, getter y setter

    bool Tienda::estaVacio(){
        if(this->stock == nullptr){
            return true;
        }else if(this->stock->getCelulares()->estaVacio() || this->stock->getPersonas()->estaVacio()){
            return true;
        }
        else return false;
    }

    void Tienda::setStock( Stock * s){
        this->stock = s;
        establecerCorreos();
    }

    Stock*  Tienda::getStock(){
        return this->stock;
    }

    //Recomendaciones de compra   

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::recomendarCelulares(Persona* persona){
       //cout<<persona->getPresupuesto() <<endl;
       return celularesPorPresupuestoMenor(persona->getPresupuesto());
    } //Recomendar automaticamente a la persona un celular por presupuesto

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMenor(double p){

        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerPrimero();
        int cont = 0;

        if (p > (stock->getCelulares()->obtenerUltimo()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                //cout<<"Entre a la condicion" <<endl;
        }

        while(cont < stock->getCelulares()->obtenerLongitud()){
            //cout<<"Entro al while grande"<<endl;
            //cout<< (it->getValor())->getPrecio() << " " << p <<endl;
            if((it->getValor())->getPrecio() > p){

               it = it->getAnterior(); 
               while(cont != 0){
                    //cout<<"Entro al while peque"<<endl;
                    //cout<< cont <<endl;
                    presupuesto->insertarFinal(it->getValor());
                    it = it->getAnterior();
                    cont --;
                }

               cont = stock->getCelulares()->obtenerLongitud();
            }else{
            it = it->getSiguiente();
            cont++;
            }
        }

        //cout<<"Llegue al final"<<endl;
        return presupuesto;
    } //Devolver los celulares menores o iguales que el presupuesto

    //!debe estar ordenada
    ListaDobleC<Celular*>* Tienda::celularesPorPresupuestoMayor(double p){

        //this->getStock()->getCelulares()->imprimirObjetoInicio();
        ListaDobleC<Celular*> *presupuesto = new  ListaDobleC<Celular*>();

        NodoDC<Celular*> *it =stock->getCelulares()->obtenerUltimo();
        int cont = 0;

        if (p < (stock->getCelulares()->obtenerPrimero()->getValor())->getPrecio()){
                presupuesto = stock->getCelulares();
                //cout<<"Entre a la condicion" <<endl;
        }

        while(cont < stock->getCelulares()->obtenerLongitud()){
            //cout<< (it->getValor())->getPrecio() << " " << p <<endl;

            if((it->getValor())->getPrecio() < p){

               it = it->getSiguiente();
               while(cont != 0){ 
                   //cout<< cont <<endl;
                   presupuesto->insertarFinal(it->getValor());
                   it = it->getSiguiente();
                   cont --;
                }

               cont = stock->getCelulares()->obtenerLongitud();
            }

            it = it->getAnterior();
            cont++;
        }
        
        return presupuesto;
    } //Devolver celulares mayores o iguales que el presupuesto

    //Devuelven listas de objetos que cumplan con ciertos requisitos

    ListaDobleC<Persona*>* Tienda::personasPorPresupuestoIgual(double valor) {

        //cout<< "Entre a la funcion encontrar" <<endl;

		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
        Celular *c = new Celular();
		int cont = 0;
		
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< "Entre al while" <<endl;
            //cout<< (c->iguales(it->getValor()->getPresupuesto(), valor, 0.01)) <<endl;
			if (c->iguales(it->getValor()->getPresupuesto(), valor, 0.01)){
				l->insertarFinal(it->getValor());
                //cout<<"Entro al if"<<endl;
            }   
				
			it = it->getSiguiente();
			cont++;
		}
		
        //cout<<"Salgo de la funcion"<<endl;
		return l;
	}
	
	ListaDobleC<Persona*>* Tienda::personasPorNombreIgual(string nombre, string apellido) {

        //cout<< "Entre a la funcion encontrar" <<endl;
		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;

			if (it->getValor()->getNombre() == nombre && it->getValor()->getApellido() == apellido){
				l->insertarFinal(it->getValor());
                //cout<< "Entre al if y agregue" <<endl;
            }
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
	}

    ListaDobleC<Persona*>* Tienda::personasIgual(string nombre, string apellido, double presupuesto, int cedula){
         
        Persona *p = new Persona(nombre, apellido, presupuesto, cedula); 
        //cout<< "Entre a la funcion encontrar" <<endl;
		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;

			if ((*(it->getValor()) == *p)){
				l->insertarFinal(it->getValor());
                //cout<< "Entre al if y agregue" <<endl;
            }
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }

    ListaDobleC<Persona*>* Tienda::personasIgual(string nombre, string apellido, unsigned long cedula){
         
        //Persona *p = new Persona(nombre, apellido, cedula); 
        //cout<< "Entre a la funcion encontrar" <<endl;
		ListaDobleC<Persona*>* l = new ListaDobleC<Persona*>();
		NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getPersonas()->obtenerLongitud()) {
            //cout<< it->getValor()->getNombre() <<endl;

			if (it->getValor()->getNombre() == nombre && it->getValor()->getApellido() == apellido && it->getValor()->getCedula() == cedula){
				l->insertarFinal(it->getValor());
                //cout<< "Entre al if y agregue" <<endl;
            }
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }




    ListaDobleC<Celular*>* Tienda::celularesPorPrecioIgual(double pres){

        //cout<< "stock->getCelulares()->obtenerLongitud()" <<endl;

        ListaDobleC<Celular*>* l = new ListaDobleC<Celular*>();
		NodoDC<Celular*> *it = stock->getCelulares()->obtenerPrimero();
		int cont = 0;
		
        //cout << valor <<endl;
		while (cont < stock->getCelulares()->obtenerLongitud()) {
            //cout<< it->getValor()->getPrecio() <<endl;
			if (it->getValor()->getPrecio() == pres){
                //cout<< "Entro al if"<<endl;
				l->insertarFinal(it->getValor());
            }
			it = it->getSiguiente();
			cont++;
		}
		
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }

	ListaDobleC<Celular*>* Tienda::celularesPorMarcaIgual(string nombre){

        //cout<< stock->getCelulares()->obtenerLongitud()<<endl;
        ListaDobleC<Celular*>* l = new ListaDobleC<Celular*>();
		NodoDC<Celular*> *it = stock->getCelulares()->obtenerPrimero();
		int cont = 0;
		
        //cout << nombre <<endl;

		while (cont < stock->getCelulares()->obtenerLongitud()) {
            // /cout<< it->getValor()->getMarca() <<endl;

			if (it->getValor()->getMarca() == nombre)
				l->insertarFinal(it->getValor());
				
			it = it->getSiguiente();
			cont++;
		}

        /*
        if(l->obtenerPrimero() == nullptr){
            cout<< "No se encontro la instancia"<<endl;
        }
        */
        //cout << "llegue al final" <<endl;
        //l->imprimirObjetoFinal();
		return l;
    }


    void Tienda::agregarCelularTienda(Celular* nuevo){

        if(stock->compararCelulares(nuevo)){

            cout<< "\n \n \n";
            stock->agregarStockRepetido(nuevo, nuevo->getStock());
            stock->verCelulares();

            cout << "\n~~~ El celular que desea agregar ya existe. Se ha aumentado el stock ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getCelulares()->insertarFinal(nuevo);
            stock->verCelulares();
            cout << "\n~~~ El celular se ha agregado con exito ~~~\n" <<endl;
        }

        //cout<<stock->getCelulares()->obtenerLongitud()<<endl;

    }

    void Tienda::eliminarCelularTienda(Celular* c){

        if(stock->eliminarCelular(c)){
            cout<<"\n";
            stock->verCelulares();

            cout<< "\n ~~ Celular eliminado con exito ~~\n";
        }else{
            cout<< "\n ~~ Ningun celular corresponde a estos datos. ~~\n";
        }

        //cout<<stock->getCelulares()->obtenerLongitud()<<endl;
    }

    void Tienda::comprarCelular(string celular, string persona, string apersona, double presupuesto, long cedula){

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, presupuesto, cedula);

        if(c != nullptr && p!= nullptr){
            //cout<< "Compro celu" <<endl;
            p -> comprarCelular(c);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ Probablemente no se tiene suficiente presupuesto ~~~\n" <<endl;
        }
    }

    void  Tienda::comprarCelular(string celular, string persona, string apersona, double presupuesto, int cantidad, long cedula){

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, presupuesto, cedula);

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c, cantidad);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }

    void Tienda::comprarCelular(string celular, string persona, string apersona, long cedula){

        //cout<< "Entro a comprar celular unico" <<endl;

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, cedula);

        cout << p->getPresupuesto() <<endl;

        if(c != nullptr && p!= nullptr){
            //cout<< "Compro celu" <<endl;
            p -> comprarCelular(c);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ Probablemente no se tiene suficiente presupuesto ~~~\n" <<endl;
        }
    }

    void  Tienda::comprarCelular(string celular, string persona, string apersona, int cantidad, long cedula){

        Celular* c = stock->retornarCelularporNombre(celular);
        Persona* p = stock->retornarPersonaporNombre(persona, apersona, cedula);

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c, cantidad);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }
   

    void Tienda::comprarCelular(Persona* p, Celular* c, int cant){

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c, cant);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }

    void Tienda::comprarCelular(Persona* p, Celular* c){

        //cout<< p->getPresupuesto() <<endl;

        if(c != nullptr && p!= nullptr){
            p -> comprarCelular(c);
        }else if(c == nullptr && p== nullptr){
            cout<< "\n~~~ No existe un celular ni una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }else if(c == nullptr){
            cout<< "\n~~~ No existe un celular que cumpla con los datos ingresados ~~~\n" <<endl;
        }else{
            cout<< "\n~~~ No existe una persona que cumpla con los datos ingresados ~~~\n" <<endl;
        }
    }

    
    void Tienda::buscarPorNombreCelular(string nombre){

        Stock *s = new Stock();
        if(celularesPorMarcaIgual(nombre)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            s->setCelulares(celularesPorMarcaIgual(nombre));
            s -> verStock();
            free(s);
        }

    }

    void Tienda::buscarPorPrecioCelular(double precio){

        Stock *a = new Stock();
        if(celularesPorPrecioIgual(precio)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            a -> setCelulares(celularesPorPrecioIgual(precio));
            a ->verStock();
            free(a);
        }
    }

    void Tienda::agregarPersonaTienda(Persona* p){
        
        if(stock->compararPersona(p)){

            cout << "\n~~~ La persona que desea registrar ya se encuentra en la Lista ~~~" <<endl;

        }else{

            cout<< "\n \n \n";
            stock->getPersonas()->insertarFinal(p);
            establecerCorreos();
            stock->verPersonas();
            cout << "\n\n~~~ La persona ha agregado con exito ~~~\n" <<endl;
        }
    }

    void Tienda::eliminarPersonaTienda(Persona* p){

        if(stock->eliminarPersona(p)){
            cout<<"\n";
            stock->verPersonas();

            cout<< "\n ~~ Persona eliminada con exito ~~\n";
        }else{
            cout<< "\n ~~ Ninguna persona corresponde a estos datos. ~~\n";
        }
    }

    void Tienda::buscarPorNombrePersona(string nombre, string apellido){
        Stock *a = new Stock();

        //cout<< "Entre a la funcion buscar" <<endl;
        if(personasPorNombreIgual(nombre, apellido)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            //cout<< "Holi" <<endl;
            a -> setPersonas(personasPorNombreIgual(nombre, apellido));
            //cout<< "Holi2" <<endl;
            //a -> getPersonas() ->imprimirObjetoFinal();
            a ->verPersonas();
            free(a);
        }
    }
    
    void Tienda::buscarPorPresupuestoPersona(double presupuesto){
        Stock *a = new Stock();
        //cout<< "Entre a la funcion buscar" <<endl;
        if(personasPorPresupuestoIgual(presupuesto)->estaVacio()){
            cout <<"\n ~~~ No se ha encontrado aquel criterio ~~~ \n";
        }else{
            cout<< "\n";
            a -> setPersonas(personasPorPresupuestoIgual(presupuesto));
            a ->verPersonas();
            free(a);
        }
    }

    bool Tienda::recomendarAutomatico(string nombre, string apellido, double presupuesto, int cedula){
        this->stock->ordenarPorPrecio();
        Stock *por = new Stock();

        por -> setPersonas(personasIgual(nombre, apellido, cedula));

        if(por->getPersonas()->obtenerPrimero() != nullptr){
            por -> setCelulares(recomendarCelulares(por->getPersonas()->obtenerPrimero()->getValor()));
            por -> verCelulares();
            return true;
        }else{
            cout<< "\n~~~ No se han encontrado coincidencias ~~~\n" <<endl;
            return false;
        }

        free(por);
    }

    bool Tienda::recomendarMenores(double presupuesto){
        this->stock->ordenarPorPrecio();

        Stock *por = new Stock();

        por -> setCelulares(celularesPorPresupuestoMenor(presupuesto));
        if(por->getCelulares()->obtenerPrimero() != nullptr){
            por -> verCelulares();
            return true;
        }else{
            cout<< "\n~~~ No se han encontrado coincidencias ~~~\n" <<endl;
            return false;
        }

        free(por);
    }

    bool Tienda::recomendarMayores(double presupuesto){
        this->stock->ordenarPorPrecio();

        Stock *por = new Stock();

        por -> setCelulares(celularesPorPresupuestoMayor(presupuesto));
        
        if(por->getCelulares()->obtenerPrimero() != nullptr){
            por -> verCelulares();
            return true;
        }else{
             cout<< "\n~~~ No se han encontrado coincidencias ~~~\n" <<endl;
             return true;
        }
        
        free(por);
    }

     void Tienda::establecerCorreos(){

        //cout<< "Establezco correos"<<endl;
        NodoDC<Persona*> *it = stock->getPersonas()->obtenerPrimero();
        string nombre;
        string apellido;
        int cont = 0;

        //cout<< stock->getPersonas()->obtenerLongitud() <<endl;

        while(cont < stock->getPersonas()->obtenerLongitud()){

            int cuenta = 0;

            nombre = it->getValor()->getNombre();
            apellido = it->getValor()->getApellido();

            ListaDobleC<Persona*>* repetidos = personasPorNombreIgual(nombre, apellido);
            NodoDC<Persona*> *itRepetidos = repetidos->obtenerPrimero();
            //cout<< itRepetidos->toString()<<endl;

            if(repetidos->obtenerLongitud() == 1){

                itRepetidos->getValor()->setCorreo(stock->generarCorreo(nombre, apellido));
                //cout<< stock->generarCorreo(nombre, apellido) << " correo a asignar"<<endl;
                //cout<< itRepetidos ->getValor()->getCorreo() << " correo asignado" <<endl;
                //cout<< "Unico nombre"<<endl;

            }else if(repetidos->estaVacio()){
                cout << "~~~ Ocurrio un percance ~~~" <<endl;
                cont = stock->getPersonas()->obtenerLongitud();
            }else{
                
                //cout<< "Varios"<<endl;
                if(repetidos->obtenerPrimero()->getValor()->tieneCorreo()){
                    //cout<< "NO he establecido correos"<<endl;
                int cant;
                while(cant < repetidos->obtenerLongitud()){
                    itRepetidos->getValor()->setCorreo(stock->generarCorreo(nombre, apellido, cuenta));
                    //cout<< itRepetidos ->getValor()->getCorreo() << " correo asignado" <<endl;
                    itRepetidos = itRepetidos ->getSiguiente();
                    cuenta++;
                    cant++;
                }

                }

            }

            cont++;
            it = it->getSiguiente();
        }

    }

    bool Tienda::cedulaCorrecta(int c){
        string ced = to_string(c);
        int t = ced.length();

        if(t < 10 || t > 10){
            return false;
        }
        
        return true;
    }

    bool Tienda::stockCorrecto(int s){
        return (s > 0);
    }

    bool Tienda::presupuestoCorrecto(double p){
        return (p > stock->menorPrecioCelular());
    }