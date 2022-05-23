#ifndef NUMERO_H
#define NUMERO_H
#include <vector>
#include <string>
using std::vector;
using namespace std;

class Numero{
    private:
        vector<int> nums;
    public:
        Numero(string s);
        vector<int> creacionVector(string);
        int euclidesMCD(int, int);
        void imprimirLongitudVector();
        void imprimirDatosVector();
};
#endif 