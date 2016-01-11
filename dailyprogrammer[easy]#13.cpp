#include <iostream>
#include <stdlib.h>
using namespace std;
/*
Find the number of the year for the given date. 
For example, january 1st would be 1, and december 31st is 365.
for extra credit, allow it to calculate leap years, as well.
*/
int
main(int argc, char** argv){
    int month = atoi(argv[1])-1;
    int day = atoi(argv[2]);
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string input;
    cout << "Is your year is leap year ? (y/n)" << endl;
    cin >> input;
    if (input == "y")
        months[1] = 29;
    int whichDay = 0;
    for(unsigned int i = 0; i < month; ++i){
        whichDay += months[i];
    }
    cout << whichDay + day << endl;
}