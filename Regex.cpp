
#include "Regex.h"

/**
 * Toma una cadena y devuelve una pila de cadenas
 * 
 * @param s La cadena a analizar
 * 
 * @return Un puntero a un objeto Pila<string>.
 */
Pila<string>* Regex::fragmento(const string &s){

    Pila<string> *frag = new Pila<string>();

   /* Una expresión regular que coincida con lo siguiente: */
    regex r("([0-9]+([.][0-9]*)?|[.][0-9]+|e|pi)|[+-^*/]|sin|sen|cos|tan|sinh|senh|cosh|tanh|csc|sec|ctg|ln|log10|log|[(]|[)]|rt");

    for (
    std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
    i != std::sregex_iterator();
    ++i 
    )
    {
        smatch m = *i;
        longitud += m.length();
        frag->push(m.str());
    }

    return frag;
}

/**
 * Compara la longitud de la cadena con la longitud de la expresión regular. Sirve para saber si se detecto un error
 * de sintaxis.
 * 
 * @param l longitud de la cadena
 * 
 * @return un valor booleano.
 */
bool Regex::compararLongitudes(int l){
    return l == longitud;
}

/**
 * Devuelve verdadero si la cadena es un número, falso en caso contrario
 * 
 * @param a La cadena a probar.
 * 
 * @return Un valor booleano.
 */
bool Regex::esUnNumero(const string &a){
    const regex r("^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$");
    return regex_match(a,r);
}

bool Regex::esUnOperando(const string &a){
    return esUnMas(a) || esUnMenos(a) || esUnaMultiplicacion(a) || esUnaDivision(a) || esUnExponente(a) || esUnaRaiz(a) ||esUnSeno(a) || esUnCoseno(a) || esUnTangente(a) || esUnCosecante(a) || esUnSecante(a) || esUnCotangente(a) || esUnSenh(a) || esUnCosh(a) || esUnTanh(a) || esUnln(a) || esUnlog10(a) || esUnlog(a);
}

bool Regex::esUnMas(const string &a){
    const regex r("[+]");
    return regex_match(a,r);
}

bool Regex::esUnMenos(const string &a){
    const regex r("[-]");
    return regex_match(a,r);
}

bool Regex::esUnaDivision(const string &a){
    const regex r("[/]");
    return regex_match(a,r);
}

bool Regex::esUnaMultiplicacion(const string &a){
    const regex r("[*]");
    return regex_match(a,r);
}

bool Regex::esUnExponente(const string &a){
    const regex r("[^]");
    return regex_match(a,r);
}

bool Regex::esUnaRaiz(const string &a){
    const regex r("rt");
    return regex_match(a,r);
}

bool Regex::esUnSeno(const string &a){
    const regex r("sin|sen");
    return regex_match(a,r);
}

bool Regex::esUnCoseno(const string &a){
    const regex r("cos");
    return regex_match(a,r);
}

bool Regex::esUnTangente(const string &a){
    const regex r("tan");
    return regex_match(a,r);
}

bool Regex::esUnCosecante(const string &a){
    const regex r("csc");
    return regex_match(a,r);
}

bool Regex::esUnSecante(const string &a){
    const regex r("sec");
    return regex_match(a,r);
}

bool Regex::esUnCotangente(const string &a){
    const regex r("ctg");
    return regex_match(a,r);
}

bool Regex::esUnSenh(const string &a){
    const regex r("sinh|senh");
    return regex_match(a,r);
}

bool Regex::esUnCosh(const string &a){
    const regex r("cosh");
    return regex_match(a,r);
}

bool Regex::esUnTanh(const string &a){
    const regex r("tanh");
    return regex_match(a,r);
}

bool Regex::esUnln(const string &a){
    const regex r("ln");
    return regex_match(a,r);
}

bool Regex::esUnlog10(const string &a){
    const regex r("log10");
    return regex_match(a,r);
}

bool Regex::esUnlog(const string &a){
    const regex r("log");
    return regex_match(a,r);
}