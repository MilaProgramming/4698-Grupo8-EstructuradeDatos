// Rotate.cpp : main project file.

#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

void gotoXY( SHORT x, SHORT y ) ;

int main()
{
    std::string rotate_right = "rotating right..." ;
    std::string rotate_left = "rotating left..." ;

    do
    {
        gotoXY(14,13);
        std::cout << rotate_right << '|' << rotate_left ;
        Sleep(200);
        std::rotate( rotate_right.begin(), rotate_right.end()-1, rotate_right.end() ) ;
        std::rotate( rotate_left.begin(), rotate_left.begin()+1, rotate_left.end() ) ;
    }
    while(true);
}

void gotoXY( SHORT x, SHORT y )
{
    static const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD CursorPosition = { x, y } ;
    SetConsoleCursorPosition(console,CursorPosition);
}