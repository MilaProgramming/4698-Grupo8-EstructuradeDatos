#include <iostream>
#include "sobrecarga.cpp"
int main(int argc, char** argv){
printf("%d",suma(5));
printf("\n%f",suma(6,5));
printf("\n%.2lf",suma(6,8.8));
printf("\n%s",suma(6,8,8));
return 0;
}