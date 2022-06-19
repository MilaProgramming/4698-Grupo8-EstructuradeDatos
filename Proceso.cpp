#include <iostream>
#include "Proceso.h"
using namespace std;
#pragma once

    Pila<string>* Proceso::getInfija(){
        return this->infija;
    }

    void Proceso::setInfija(Pila<string> *i) {
        this ->infija = i;
    }

    Pila<string> *Proceso::getPostfija(){
        return postfija;
    }

    void Proceso::setPostfija(Pila<string> *post) {
        postfija = post;
    }

    Pila<string> *Proceso::getPrefija(){
        return prefija;
    }

    
    void Proceso::setPrefija(Pila<string> *pre) {
        prefija = pre;
    }

   
    /**
     * La función recibe una cadena del usuario, luego usa una expresión regular para dividir la cadena en tokens
     * y luego empuja esos tokens en una pila una cadena del usuario. Despues, la pila de cadenas se empuja a otra pila, que 
     * luego se imprime
     * @return un valor booleano.
     */
    bool Proceso::recibirExpresion(){

        string input{"0"};

        /*Obtener la entrada del usuario. */
        getline(cin,input);
        reemplazoSignos(input);

        if(buscoSignos(input)){

            int longitud = input.length();

            Pila<string> *fragmento= r->fragmento(input);

            /* Empujando los valores de la pila de fragmentos en la pila infija. */
            Nodo<string> *n = fragmento->getPrimero();
            while(n != nullptr){        
                infija->push(n->getValor());
                n = n->getNodo();
            }

            /* Comprobando si la longitud de la entrada es la misma que la longitud de la pila. */
            if(r->compararLongitudes(longitud)){
                cout<< "\nExpresion leida con exito"<<endl;
                reemplazoMenos(input);
                //cout << input <<endl;
                //infija->imprimirT();
                return true;
            }else{
                cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
            }

        }else{
            cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis2"<<endl;
        }

        return false;
    }

    void Proceso::convertirPostfija(){

        Pila<string> *conversion = new Pila<string>();
        //cout << "Estoy en el inicio de convertir"<<endl;
        /* Comprobando si la pila está vacía. */
        while(!(infija->estaVacia())){

            /* Creando una nueva cadena llamada token y asignándole el valor de la parte superior de la
            pila. Ademas, elimino el valor de la pila infija*/
            //cout << infija->getLongitud() << "longitud inicial" <<endl;
            string token{infija->pop()};
            //cout << infija->getLongitud() << "longitud luego del pop" <<endl;
            //system("pause");

            if(r->esUnNumero(token)){
                //cout << token <<" token que es numero" <<endl;
                postfija ->push(token);
               // system("pause");
                
            }else{

                /**
                 * Operador actual 
                 * + -> 1
                 * - -> 2
                 * * -> 3
                 * / -> 4
                 * ~ (signo) -> 5
        
                 * Prioridades de los operadores respectivos
                 * 
                 * + - -> prioridad 5
                 * * / -> prioridad 4
                 */

                /**
                 * Si la pila de conversion esta vacia
                 * o si el operador en su tope tiene mayor prioridad que el de 
                 * token.
                 */
                if(conversion->estaVacia() || prioridades(operadores(token)) < prioridades(operadores(conversion->tope()))){
                    //cout << token <<" token que es de pila vacia o de operador de menor prioridad" <<endl;
                    conversion -> push(token);
                }else if(prioridades(operadores(token)) >= prioridades(operadores(conversion->tope())) && r->esUnBinario(token)){
                    //cout << token <<" token de operador de mayor prioridad" <<endl;
                    postfija->push(conversion->pop());
                    conversion->push(token);
                }
       
            }
        
        }

        if(!(conversion->estaVacia())){
            while(!(conversion->estaVacia())){
                postfija->push(conversion->pop());            
            }
             //cout<< "Llegue a la condicion de impresion 1"<<endl;
            postfija->imprimir();
            //system("pause");
        }else{
            //cout<< "Llegue a la condicion de impresion"<<endl;
            postfija->imprimir();
            //system("pause");
        }
    }



    /**
     * Toma una cadena como parámetro y devuelve un número entero
     * + -> 1
     * - -> 2
     * * -> 3
     * / -> 4
     * ~ (signo) -> 5
     * @param a La cadena a comprobar
     * 
     * @return El valor devuelto es el resultado de la operación.
     */
    int Proceso::operadores(const string &a){

        if(r->esUnMas(a)){
            return 1;
        }else if(r->esUnMenos(a)){
            return 2;
        }else if(r->esUnaMultiplicacion(a)){
            return 3;
        }else if(r->esUnaDivision(a)){
            return 4;
        }else if(r->esUnSigno(a)){
            return 5;
        }

        return 0;
    }


    /**
     * Devuelve la prioridad del operador
     * 
     * + - -> prioridad 5
     * * / -> prioridad 4
     * 
     * @param operador 1 = +, 2 = -, 3 = *, 4 = /
     * 
     * @return El valor de retorno es la prioridad del operador.
     */
    int Proceso::prioridades(int operador){

        if(operador == 1 || operador == 2){
            return pSumaResta();
        }else if(operador == 3 || operador == 4){
            return pMultiplicacionDivision();
        }

        return 0;
    }

    /**
     * Devuelve el valor de la variable numero.
     * 
     * @return El valor devuelto es el valor de la variable numero.
    */

    int Proceso::pSumaResta(){
        return 1;
    }

    int Proceso::pMultiplicacionDivision(){
        return 2;
    } 

    int Proceso::pExponenteRaiz(){
        return 3;
    }

    int Proceso::pTrigonometricasLog(){
        return 4;
    }

    int Proceso::pParentesis(){
        return 5;
    }

    int Proceso::pSigno(){
        return 6;
    }
    
    /**
     * Reemplaza todas las apariciones de una cadena con otra cadena
     * 
     * @param subject La cadena que se va a buscar y reemplazar.
     * @param search La cadena a buscar.
     * @param replace La cadena con la que reemplazar la cadena de búsqueda.
     */
    void Proceso::reemplazaString(string& subject, const string& search, const string& replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }

   /**
    * Reemplaza todas las instancias de la cadena "(-" con la cadena "(~" en la cadena str
    * 
    * @param str La cadena que se va a modificar.
    */
    void Proceso::reemplazoSignos(string& str){
        reemplazaString(str, "(-", "(~");
    }

    void Proceso::reemplazoMenos(string& str){
        reemplazaString(str, "~", "-");
    }

    /**
     * Comprueba si hay dos signos consecutivos en una cadena
     * Cubro basicos errores de sintaxis
     * 
     * @param str La cadena a comprobar
     * 
     * @return un valor booleano.
     */
    bool Proceso::buscoSignos(string& str){

        if (str.find("++") != string::npos) {
            return false;
        }else if(str.find("--") != string::npos){
            return false;
        }else if(str.find("-+") != string::npos){
            return false;
        }else if(str.find("+-") != string::npos){
            return false;
        }else if(str.find("**") != string::npos){
            return false;
        }

        return true;
    }