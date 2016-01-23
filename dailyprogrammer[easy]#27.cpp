#include <iostream>
using namespace std;
#define __ 100
#define _____ 0
ostream& ____ = cout;
istream& ___ = cin;
/*
Write a program that accepts a year as input and outputs the century the 
year belongs in (e.g. 18th century's year ranges are 1701 to 1800) and whether
or not the year is a leap year,
Sample run:
Enter Year: 1996
Century: 20
Leap Year: Yes
*/
void
__f(int _1){
    int _ = _____;
    while(_1 > 0){
        _1 = _1 - __;
        ++_;
    }
    ____ << _;
}
int
main(void){
    int _;
    ____ << "Enter a year: ";
    ___ >> _;
    ____ << "Century : "; __f((_-!_____));
    ____ << endl << "Leap Year : " 
        << (((!(_%(!_____+!_____+!_____+!_____))&&_%__)||(!(_%__)&&!(_/__%(!_____+!_____+!_____+!_____)))) ? "Yes" : "No")
        << endl;
}