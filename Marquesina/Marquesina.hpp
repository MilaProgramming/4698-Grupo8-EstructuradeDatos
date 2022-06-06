#pragma once

#include <iostream>
#include "ListaDC.hpp"
#include <string>
#include <windows.h>

using namespace std;

template <typename T>

    class Marquesina{
        private:
            string str = "\0";
            ListaDobleC<char> *lista= new ListaDobleC<char>();

            
            int obtenerLongitudConsola(){
                CONSOLE_SCREEN_BUFFER_INFO coso;
                int longitud;

                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coso);
                longitud = coso.srWindow.Right - coso.srWindow.Left + 1;

                return longitud;
            }

            void conviertoChars(){
                for(long long unsigned int i = 0; i < str.length(); i++)
                lista->insertarFinal(str[i]);
            }

            void rellenoEspacios(){
                for(int i = 0; i<obtenerLongitudConsola(); i++)
                lista->insertarFinal(' ');
            }

            void imprimirLista(NodoDC<T> *nimpreso){
                if (lista->estaVacio()){ 
                    cout<< "Lista vacia. No existe nada imprimir"<<endl;
                    return;
                }else{ 
                    int max = obtenerLongitudConsola();
                    while(max != 0){
                        cout<< nimpreso -> getValor();
                        nimpreso = nimpreso->getSiguiente();
                        max--;
                    }

                }
            }
            
        public:    
            Marquesina(string s){
                this->str = s;
            }

            ~Marquesina(){
                free(this->lista);
            }
       
            ListaDobleC<char>* getLista(){
                return this->lista;
            }


            void bucleMarquesina(){

                conviertoChars();
                rellenoEspacios();

                NodoDC<T> *it = lista->getPrimero();
                do{
                    system("cls");
                    imprimirLista(it);
                    Sleep(50);
                    it = it->getSiguiente();

                }while(true);

                
            }       
    };