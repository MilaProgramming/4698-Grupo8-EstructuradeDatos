#include"B.h"

void B::defineB(int x)
{    b = x; 
}

int B::dameB(void)
{    return b; 
}

int P(A OA)
{    B Ob;
     Ob.defineB(2);
     return OA.a*Ob.b; 
}
