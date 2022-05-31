//!Plantilla para metodos aritmeticos de dos numeros

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
    class Calculadora{
        private:

        public:

            Calculadora(){

            }    

            int obtenerMCD(int a, int b){
                if (a == 0){
                    return b;
                }else if (b == 0){
                    return a;
                }else{
                    return obtenerMCD(b, a%b);
                }
            }

            int obtenerMCM(int a, int b){
                return (a*b)/obtenerMCD(a,b);
            }

            T* convertirRealenFraccion(T input){
                T integral = floor(input);
                T frac = input - integral;

                const long precision = 1000000000; // This is the accuracy.

                T mcd = obtenerMCD(round(frac * precision), precision);

                T denominador = precision / mcd;
                T numerador = round(frac * precision) / mcd;

                T* fraccion = new T[1];
                fraccion[1] = denominador;
                fraccion[0] = numerador;

                return fraccion;
            } 
    };