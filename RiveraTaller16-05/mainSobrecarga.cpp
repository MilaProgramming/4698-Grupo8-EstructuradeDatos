
#include "Sobrecarga.cpp"

int main(){

    Sobrecarga *s = new Sobrecarga();

    printf("%i \n", s -> suma(2));
    printf("%f \n", s -> suma(2,5));
    printf("%f \n", s -> suma(2,4.6));
    printf("%s \n", s -> suma(3,4,5));
  
    return 0;
}