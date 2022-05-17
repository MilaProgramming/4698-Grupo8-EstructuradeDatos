//[11:00 AM] MSc. EDGAR FERNANDO SOLIS ACOSTA

#include <iostream>

int suma(int);
float suma(int,int);
double suma(int,float);
char *suma(int,int,int);

int suma(int n){
    return n*5;
}

float suma(int n,int m){
    return (float)n*(float)m;
}

double suma(int n, double f){
    return (double)n*f;
}

char *suma(int a,int b,int c){
    return "hola mundo";
}

int main(){

    printf("%d",suma(5));
    printf("\n%f",suma(6,5));
    printf("\n%.2lf",suma(6,8.8));
    printf("\n%s",suma(6,8,8));

    return 0;
}
