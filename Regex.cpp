
#include "Regex.h"

    bool Regex::esUnNumero(const string &a){
        const regex r("^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$");
        return regex_match(a,r);
    }

    Pila<string>* Regex::fragmento(const string &s){
        Pila<string> *frag = new Pila<string>();

        regex r("([0-9]+([.][0-9]*)?|[.][0-9]+|e|pi)|[+-^*/]|sin|cos|tan|sinh|cosh|tanh|[(]|[)]");

        for (
        std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
        i != std::sregex_iterator();
        ++i 
        )
        {
            smatch m = *i;
            longitud += m.length();
            //cout << m.str() << " coso"<<endl;
            frag->push(m.str());
            //cout << m.str() << " at position " << m.position() << '\n';
        }

        //frag->imprimir();
        return frag;
    }