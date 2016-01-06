#include <iostream>
#include <string>
using namespace std;
/*
write a program that will print the song "99 bottles of beer on the wall".
for extra credit, do not allow the program to print each loop on a new line.
*/
/*
99 bottles of beer on the wall, 99 bottles of beer.
Take one down and pass it around, 98 bottles of beer on the wall.
*/
int
main(void){
    int i = 99;  string bottle = " bottles of beer"; string take = "Take one down and pass it around, "; 
    string wall = " on the wall";
    while(true){
        if (i==1){
           cout << i <<  bottle << wall << "," << i << bottle << "." << endl
            << take << "no more" << bottle << wall << "." << endl << endl;
            break; 
        }
        cout << i <<  bottle << wall << "," << i << bottle << "." << endl
            << take << i-1 << bottle << wall << "." << endl << endl;

        --i;
    }
}