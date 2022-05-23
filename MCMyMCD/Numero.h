#ifndef NUMERO_H
#define NUMERO_H
#include <vector>
#include <string>
using std::vector;
using namespace std;

class Numero{
    private:
        vector<int> nums;
        int euclidesMCD(int, int);
    public:
        Numero(string s);
        vector<int> creacionVector(string);
        int obtenerMCD();
        void imprimirLongitudVector();
        void imprimirDatosVector();
};
#endif 