#include "NumeroA.cpp"

int main ()

{   NumeroA n1(2) , n2(23), n3(62), n4(96);
     n2+=n2;
     cout << "Numero " << n2.getNumeroA() << endl;

     n3+=n3;
     cout << "Numero " << n3.getNumeroA() << endl;
    return 0;

}

