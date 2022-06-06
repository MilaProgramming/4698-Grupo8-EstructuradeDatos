// Rotate.cpp : main project file.

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y);

int main()
{
	string rotating_string =  "Hola Mundo...";
	int len = rotating_string.length();
	char letter_holder;
	do
	{
		for (int m=4;m<80-(len+1);m++)
		{
			for (int o=0;o<len;o++)
			{
				gotoXY(m,13);
				cout << rotating_string << " ";
				Sleep(100);
				letter_holder = rotating_string[0];
				for( int x=0;x<len;x++)
				{
					rotating_string[x] = rotating_string[x+1];
				}
				rotating_string[len-1] = letter_holder;

			}
		}

		for (int m=80-(len+1);m>3;m--)
		{
			for (int o=0;o<len;o++)
			{
				gotoXY(m,1);
				cout << rotating_string << " ";
				Sleep(100);
				letter_holder = rotating_string[0];
				for( int x=0;x<len;x++)
				{
					rotating_string[x] = rotating_string[x+1];
				}
				rotating_string[len-1] = letter_holder;

			}
		}
	} while(true);
	gotoXY(25,24);
	return 0;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}