#pragma once
#include <stdlib.h>
#include <string>  

using namespace std;
    class Conversion{
        private:

        public:
            Conversion(){} //Constructor
            ~Conversion(){} //Destructor

            int numInt(char* dato){ //Convertir a entero
                return atoi(dato); //String a int
            } 

            unsigned long numLong(char* dato){
                return atoll(dato);
            }

            float numFloat(char* dato){ //Convertir a flotante 
                return stof(dato);
            }

            double numDouble(char* dato){ //Convertir a flotante 
                return stod(dato);
            }
           
    };
