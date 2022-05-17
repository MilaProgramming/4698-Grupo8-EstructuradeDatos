#include "Reloj.cpp"

int main(){

    Reloj R(10,59,56);
    for (int i=0; i<10; i++, ++R)
    cout <<setw(4)<< R.Hora() <<setw(4)<< R.Minuto() 
         <<setw(4)<< R.Segundo() << endl;
         
    return 0;
}