/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  9 DE AGOSTO DE 2022
* FECHA DE Entrega: 10 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#pragma once
#include <stdlib.h>
#include <string>

    class Conversion{
        private:
            bool numero;
            int verificador = 0;

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
                return std::stof(dato);
            }

            void verificar(char c){ //Metodo para verificar flotante o entero  
                if (c == 46){ // 46 codigo ASCII del punto (.)
                    this -> numero = true; //Asigno verdadero si es un flotante, pues tiene punto
                } else{
                    this -> numero = false; //Asigno falso si es un entero. Pues no posee punto
                }
            }

            bool getNumero(){
                return this -> numero;
            }

            void setVerificador(int v){
                this -> verificador = v;
            }

            int getVerificador(){
                return this->verificador;
            }
    };
