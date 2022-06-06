#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y);

int main()
{
	int a=0, b=56, c=0, n=0;
	char t[25] ="Bienvenido a Borland C++";

    do
    {
        for (a=1;a<=56;a++)
        {    
            system("cls");
            gotoXY(a,1);
            cout<<t;
            Sleep (50);
        }
        for (b=56;b>=1;b--)
        {
            system("cls");
            gotoXY(b,1);
            cout<<t;
            Sleep (50);
        }

    }while (c==1);
	
	{
        getch();
    }


	return 0;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}