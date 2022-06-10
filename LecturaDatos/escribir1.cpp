#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

   ofstream file("ar.txt", ios::app);
   int num;

    while(cin >> num){
        file << num << ' ' << num <<endl;
    }
  
   file.close();
   return 0;
}