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

    bool Proceso::getCalculable(){
        return calculable;
    }

    void Proceso::setCalculable(bool calc) {
        this->calculable = calc;
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

        if(r->excepcionesBinarios(input) && r->excepciones(input) && r->excepcionesParentesis(input)){

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
                cout<< "\nExpresion leida con exito\n"<<endl;
                reemplazoMenos(input);
                //cout << input <<endl;
                infija->imprimirT();
                return true;
            }else{
                cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
            }

        }else{
            cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
        }

        return false;
    }

    void Proceso::convertirPostfija(){

        Pila<string> *conversion = new Pila<string>();
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
                //system("pause");
                
            }else{

                /**
                * Operador actual 
                * + -> 1
                * - -> 2
                * * -> 3
                * / -> 4
                * ~ (signo) -> 5
                * ^ -> 6
                * rt (raiz) -> 7
                * sin/sen -> 8
                * cos -> 9
                * tan -> 10
                * csc -> 11
                * sec -> 12
                * ctg -> 13
                * sinh -> 14
                * cosh -> 15
                * tanh -> 16
                * ln -> 17
                * log10 -> 18
                * log -> 19
                * ( -> 20
                * ) -> 21
        
                * Prioridades de los operadores respectivos
                *
                * + - -> prioridad 1
                * * / -> prioridad 2
                * ^ rt -> 3
                * Trigonometricas, logaritmicas -> 4
                * () -> 5
                * ~ -> 6
                * 
                */

                /**
                * Si la pila de conversion esta vacia
                * o si el operador en su tope tiene mayor prioridad que el de 
                * token.
                */
 
                if(r->esUnBinario(token) || r->noEsBinario(token)){

                    int cont{0};
                    int comparador{0};

                    while (cont == comparador){
                        if(conversion->estaVacia() || prioridades(operadores(token)) > prioridades(operadores(conversion->tope()))){
                            //cout << token <<" token que es de pila vacia o de operador de mayor prioridad" <<endl;
                            conversion -> push(token);
                            cont ++;
                        }else if(prioridades(operadores(token)) <= prioridades(operadores(conversion->tope()))){
                            //cout << token <<" token de operador de menor prioridad" <<endl;
                            postfija->push(conversion->pop());
                        }
                        //cout << cont <<" contador"<<endl;
                        //cout << comparador <<" comparador"<<endl;
                        //system("pause");
                    }

                    comparador++;

                }else if(r->esUnFormatoEspecial(token)){
                    
                }else if(r->esUnParentesisInicial(token)){

                }else if(r->esUnParentesisFinal(token)){

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
     * ^ -> 6
     * rt (raiz) -> 7
     * sin/sen -> 8
     * cos -> 9
     * tan -> 10
     * csc -> 11
     * sec -> 12
     * ctg -> 13
     * sinh -> 14
     * cosh -> 15
     * tanh -> 16
     * ln -> 17
     * log10 -> 18
     * log -> 19
     * ( -> 20
     * ) -> 21
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
        }else if(r->esUnExponente(a)){
            return 6;
        }else if(r->esUnaRaiz(a)){
            return 7;
        }else if(r->esUnSeno(a)){
            return 8;
        }else if(r->esUnCoseno(a)){
            return 9;
        }else if(r->esUnTangente(a)){
            return 10;
        }else if(r->esUnCosecante(a)){
            return 11;
        }else if(r->esUnSecante(a)){
            return 12;
        }else if(r->esUnCotangente(a)){
            return 13;
        }else if(r->esUnSenh(a)){
            return 14;
        }else if(r->esUnCosh(a)){
            return 15;
        }else if(r->esUnTanh(a)){
            return 16;
        }else if(r->esUnln(a)){
            return 17;
        }else if(r->esUnlog10(a)){
            return 18;
        }else if(r->esUnlog(a)){
            return 19;
        }else if(r->esUnParentesisInicial(a)){
            return 20;
        }else if(r->esUnParentesisFinal(a)){
            return 21;
        }

        return 0;
    }


    /**
     * Devuelve la prioridad del operador
     * 
     * + - -> prioridad 1
     * * / -> prioridad 2
     * ^ rt -> 3
     * Trigonometricas, logaritmicas -> 4
     * () -> 5
     * ~ -> 6
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
        }else if(operador == 6 || operador == 7){
            return pExponenteRaiz();
        }else if(operador == 8 || operador == 9 || operador == 10 || operador == 11 || operador == 12 || operador == 13 || operador == 14 || operador == 15 || operador == 16 || operador == 17 || operador == 18 || operador == 19){
            return pTrigonometricasLog();
        }else if(operador == 5){
            return pSigno();
        }else if(operador == 20 || operador == 21){
            return pParentesis();
        }

        return 0;
    }

    /** Binaridad
     * 
     * binario -> 1
     * no binario -> 2
     * parentesis inicial -> 3
     * parentesis final -> 4
     * 
     * @param a La cadena a evaluar
     * 
     * @return el tipo de operador.
     */
    int Proceso::tipoOperador(const string &a){
        
        if(r->esUnBinario(a)){
            return 1;
        }else if(r->noEsBinario(a)){
            return 2;
        }else if(r->esUnFormatoEspecial(a)){
            return 3;
        }else if(r->esUnParentesisInicial(a)){
            return 4;
        }else if(r->esUnParentesisFinal(a)){
            return 5;
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
        }else if(str.find("//") != string::npos){
            return false;
        }else if(str.find("^^") != string::npos){
            return false;
        }else if(str.find("*/") != string::npos){
            return false;
        }else if(str.find("/*") != string::npos){
            return false;
        }else if(str.find("^*") != string::npos){
            return false;
        }else if(str.find("*^") != string::npos){
            return false;
        }else if(str.find("-*") != string::npos){
            return false;
        }else if(str.find("*-") != string::npos){
            return false;
        }else if(str.find("+*") != string::npos){
            return false;
        }else if(str.find("*+") != string::npos){
            return false;
        }else if(str.find("/+") != string::npos){
            return false;
        }else if(str.find("+/") != string::npos){
            return false;
        }else if(str.find("/-") != string::npos){
            return false;
        }else if(str.find("-/") != string::npos){
            return false;
        }else if(str.find("/^") != string::npos){
            return false;
        }else if(str.find("^/") != string::npos){
            return false;
        }else if(str.find("^+") != string::npos){
            return false;
        }else if(str.find("+^") != string::npos){
            return false;
        }else if(str.find("^-") != string::npos){
            return false;
        }else if(str.find("-^") != string::npos){
            return false;
        }

        return true;
    }