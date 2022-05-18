#include<iostream>
using namespace std;

class Matematica
{
private:
    int a,b,c;
public:
    Matematica()
    {
        a=5;
        b=32;
    }
    ~Matematica()
    {
        cout<<"Memoria Destruida";
    }
    void anadir()
    {
        c=a+b;
        cout<<"Total : "<<c<<endl;
    }
};
